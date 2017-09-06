#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <set>
#include <list>
#include <iterator>

#include "graphtier.h"
#include "request_job.h"
#include "network_tester.h"

using namespace worker;
using namespace worker::query;
using namespace std;
using namespace ::improbable::graphtier;


namespace graphtier {

  using namespace request;
  using namespace pathfinding;

  namespace testing {

    NetworkTester::NetworkTester(Connection& c): connection(c) {
      dispatcher.OnEntityQueryResponse
        ([&](const EntityQueryResponseOp& op) {
          if(op.RequestId == networkRequestId){
            for(auto const& pair: op.Result){
              auto entityId = pair.first;
              auto entity = pair.second;
              auto networkData = entity.Get<NetworkData>();
              if(networkData.empty()){
                cout << "could not get network for testing" << endl;
                return;
              }
              Network network(entityId, *networkData);
              networkMap.insert({entityId, network});
            }

            cout << "Got " << networkMap.size() << " networks" << endl;

            new thread(&NetworkTester::gotNetworks, this);
          }
        });


      dispatcher.OnCommandResponse<NodeCommands::Commands::FindRoute>
        ([&](const CommandResponseOp<NodeCommands::Commands::FindRoute>& op) {
          auto request = graphTierRequestMap.find(op.RequestId);
          if(request != graphTierRequestMap.end()){
            auto promise = request->second;
            promise->set_value(*op.Response);
            graphTierRequestMap.erase(op.RequestId);
          }
        });


    }

    void NetworkTester::startTests(){
      std::this_thread::sleep_for(std::chrono::seconds(4));
      requestAllNetworks();
    }

    void printStatistics(vector<pair<TestResult, TestResult>> results){
      double totalCostFactor = 0;
      int numBothSucc = 0;
      int numDiffSucc = 0;
      int numDiffPaths = 0;

      double totalTimeTrad = 0;
      double totalTimeGT = 0;

      for(auto const& pair: results){
        totalTimeTrad += pair.first.millis;
        totalTimeGT += pair.second.millis;
        if(!pair.first.path.empty() && !pair.second.path.empty()){
          numBothSucc++;
          double costFactor = 1;
          if(pair.first.path->cost() != 0){
            costFactor = pair.second.path->cost() / pair.first.path->cost();
          }
          totalCostFactor += costFactor;
          if(abs(pair.first.path->cost() - pair.second.path->cost()) > 0.0001){
            numDiffPaths++;
          }
        }else if(pair.first.path.empty() != pair.second.path.empty()){
          numDiffSucc++;
        }
      }

      double aveCostFactor = 0;
      if(numBothSucc != 0){
        aveCostFactor = totalCostFactor / numBothSucc;
      }

      cout << "Number of tests: " << results.size() << endl;
      cout << "Total time Trad: " << totalTimeTrad << endl;
      cout << "Total time GT: " << totalTimeGT << endl;
      cout << "Average cost factor: " << aveCostFactor << endl;
      cout << "Different paths: " << numDiffPaths << endl;
      cout << "Different Success: " << numDiffSucc << endl;
    }

    void NetworkTester::gotNetworks(){
      for(auto const& network: networkMap){
        for(auto const&node: network.second.networkData.nodes()){
          //if(node.node_id() % 100 == 0){
            nodeIds.push_back(node.node_id());
          //}
        }
      }

      cout << "Got " << nodeIds.size() << " nodes" << endl;

      srand(time(NULL));

      auto numTests = 10;

      if(nodeIds.size() * nodeIds.size() > numTests){
        for(int i=0; i<numTests; i++){
          EntityId fromId = nodeIds[rand() % nodeIds.size()];
          EntityId toId = nodeIds[rand() % nodeIds.size()];
          queueTest(fromId, toId);
        }
      }else if(numTests > 0){
        for(auto const& fromId: nodeIds){
          for(auto const& toId: nodeIds){
            queueTest(fromId, toId);
          }
        }
      }

      std::this_thread::sleep_for(std::chrono::seconds(2));

      vector<pair<TestResult, TestResult>> testResults;
      while(!testQueue.empty()){
        auto pair = testQueue.front();
        testQueue.pop();
        auto result = runTest(pair.first, pair.second);
        testResults.push_back(result);
      }
      cout << "All tests complete" << endl;

      cout << endl << endl;
      printStatistics(testResults);

    }

    void NetworkTester::queueTest(EntityId from, EntityId to){
      testQueue.push({from, to});
    }

    void printResult(TestResult result){
      cout << "\t\ttime: " << result.millis << endl;
      if(result.path.empty()){
        cout << "\t\tempty";
      }else{
        cout << "\t\tcost: " << result.path->cost() << endl;
        cout << "\t\tlegs: ";
        for(auto const& leg:  result.path->legs()){
          cout << "(" << leg.from() << " - " << leg.to() << " [" << leg.network_id() << "])";
          cout << " - ";
        }
        cout << "done";
      }
      cout << endl;
    }

    pair<TestResult, TestResult> NetworkTester::runTest(EntityId from, EntityId to){
      cout << endl << endl << "Running test from " << from << " to " << to << endl;

      cout << "Traditional test starting" << endl;
      auto traditionalResult = runTraditionalTest(from, to);
      cout << "Traditional test finished" << endl;
      auto graphTierResult = runGraphTierTest(from, to);

      bool printDetails = true;

      if(traditionalResult.path.empty() != graphTierResult.path.empty()){
        cout << "different path success:" << traditionalResult.path.empty()
             << " " << graphTierResult.path.empty() << endl;
        printDetails = true;
      }else if(!traditionalResult.path.empty() && !graphTierResult.path.empty()){
        if(traditionalResult.path->cost() != graphTierResult.path->cost()){
          cout << "different costs! " << from << " to " << to << endl;
          printDetails = true;
        }
      }

      if(printDetails){
        cout << endl << "Request from " << from << " to " << to << endl;
        cout << "\t" << "Traditional:" << endl;
        printResult(traditionalResult);
        cout << "\t" << "GraphTier:" << endl;
        printResult(graphTierResult);
      }


      // if(!traditionalResult.path.empty()){
      //   cout << "path cost trad: " << traditionalResult.path->cost() << endl;
      // }
      // if(!graphTierResult.path.empty()){
      //   cout << "path cost gt: " << graphTierResult.path->cost() << endl;
      // }

      return make_pair(traditionalResult, graphTierResult);
    }

    TestResult NetworkTester::runGraphTierTest(EntityId from, EntityId to){
      using T = NodeCommands::Commands::FindRoute;
      shared_ptr<promise<const typename T::Response>>
        p(new promise<const typename T::Response>());
      future<const typename T::Response> f = p->get_future();

      auto start = std::chrono::high_resolution_clock::now();
      NodeCommands::Commands::FindRoute::Request request(to);
      auto requestId = connection.SendCommandRequest<T>(from, request, Option<uint32_t>());
      graphTierRequestMap.insert({requestId, p});

      f.wait();
      auto finish = std::chrono::high_resolution_clock::now();
      auto millis = std::chrono::duration_cast<duration<double>>(finish-start).count() * 1000;

      auto response = f.get();
      auto path = response.path();

      return TestResult {
        from, to, millis, path
          };
    }

    TestResult NetworkTester::runTraditionalTest(EntityId from, EntityId to){
      PathFinding pathFinding(networkMap);
      auto start = std::chrono::high_resolution_clock::now();
      auto path = pathFinding.search(from, to);
      auto finish = std::chrono::high_resolution_clock::now();
      auto millis = std::chrono::duration_cast<duration<double>>(finish-start).count() * 1000;
      return TestResult {
        from, to, millis, path
          };
    }

    void NetworkTester::processOpList(const OpList& op_list) {
      dispatcher.Process(op_list);
    }

    void NetworkTester::requestAllNetworks(){
      SnapshotResultType networkDataResultType{
        Option<List<ComponentId>>({NetworkData::ComponentId})
          };

      EntityQuery networkRequest = {
        ComponentConstraint{NetworkData::ComponentId},
        networkDataResultType
      };
      networkRequestId = connection
        .SendEntityQueryRequest(networkRequest, Option<uint32_t>());


    }

  }
}
