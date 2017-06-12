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
#include "pathfinding.h"

using namespace worker;
using namespace worker::query;
using namespace std;
using namespace ::improbable::graphtier;


namespace graphtier {

  using namespace request;
  using namespace pathfinding;

  namespace testing {


    ComponentId NETWORK_DATA_COMPONENT_ID = 8002;

    NetworkTester::NetworkTester(Connection& c): connection(c) {
      dispatcher.OnEntityQueryResponse
        ([&](const EntityQueryResponseOp& op) {
          if(op.RequestId == networkRequestId){
            cout << "got query " << op.ResultCount << endl;
            map<EntityId, Network> networkMap;
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

            cout << "got " << networkMap.size() << endl;

            auto start = std::chrono::high_resolution_clock::now();

            PathFinding pathFinding(networkMap);

            auto path = pathFinding.search(55, 531);


            auto finish = std::chrono::high_resolution_clock::now();
            auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count();
            std::cout << "time: " << millis << "ms" << endl;


            cout << "path cost: " << path->cost() << endl;

          }
        });

      requestAllNetworks();
    }

    void NetworkTester::processOpList(const OpList& op_list) {
      dispatcher.Process(op_list);
    }

    void NetworkTester::requestAllNetworks(){
      SnapshotResultType networkDataResultType{
        Option<List<ComponentId>>({NETWORK_DATA_COMPONENT_ID})
          };

      EntityQuery networkRequest = {
        ComponentConstraint{NETWORK_DATA_COMPONENT_ID},
        networkDataResultType
      };
      networkRequestId = connection
        .SendEntityQueryRequest(networkRequest, Option<uint32_t>());


    }

  }
}
