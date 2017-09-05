#include <improbable/worker.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <improbable/graphtier/NetworkCommands.h>


#include <improbable/graphtier/NodeCommands.h>


#include "graphtier.h"
#include "network.h"
#include "request_manager.h"
#include "network_tester.h"
#include "rpc_futures.h"

using namespace worker;
using namespace std;

using namespace graphtier;


// EntityId from = 235;
// EntityId to = 32421;



// // Dirty hack
// void waitForNetworks(worker::Connection& connection) {
//   View dispatcher;

//   EntityId waitForId = to;

//   while (true) {
//     auto op_list = connection.GetOpList(50000);
//     dispatcher.Process(op_list);
//     if(dispatcher.Entities.size() % 100 == 0){
//       cout << "\r" << dispatcher.Entities.size() << " loaded entities" << flush;
//     }
//     if(dispatcher.Entities.find(waitForId) != dispatcher.Entities.end()){
//       cout << endl;
//       break;
//     }
//   }
// }

// void testTask(Connection& connection, RpcFutures& rpcFutures){
//   std::this_thread::sleep_for(std::chrono::seconds(10));



//   cout << "Sending request" << endl;

//   NodeCommands::Commands::FindRoute::Request request(to);

//   auto start = std::chrono::high_resolution_clock::now();
//   auto f = rpcFutures.sendCommandRequest<NodeCommands::Commands::FindRoute>
//     (connection, from, request, Option<uint32_t>());
//   f.wait();

//   auto finish = std::chrono::high_resolution_clock::now();
//   auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count();
//   std::cout << "request time: " << millis << "ms" << endl;

//   auto response = f.get();
//   if(!response.path().empty()){
//     cout << "path successful: " << (*response.path()).cost() << endl;
//     for(auto const& leg: response.path()->legs()){
//       cout << "leg: " << leg.from() << " - " << leg.to() << "  " << leg.cost() << endl;
//     }
//   }else{
//     cout << "no path found" << endl;
//   }

// }




int main(int argc, char** argv) {
  // TODO: do args
  // if (argc < 2 || 3 < argc) {
    // return 1;
  // }


  EntityId from = atoi(argv[2]);
  EntityId to = atoi(argv[3]);

  worker::ConnectionParameters parameters;
  parameters.WorkerType = "graphtier";
  parameters.WorkerId = argv[1];
  parameters.Network.ConnectionType = worker::NetworkConnectionType::kTcp;
  parameters.Network.UseExternalIp = false;

  std::string hostname = "localhost";
  if (argc == 3) {
    hostname = argv[2];
  }

  worker::Connection connection = Connection::ConnectAsync(hostname, 7777, parameters).Get();

  // waitForNetworks(connection);

  RpcFutures rpcFutures;
  // network::NetworkWorker networkWorker(connection);
  request::RequestManager requestManager(connection);
  testing::NetworkTester networkTester(connection);

  // networkTester.queueTest(from, to);

  View waitForEntitiesView;
  bool waitingForEntities = true;

  while (true) {
    auto op_list = connection.GetOpList(10000);
    if(waitingForEntities){
      waitForEntitiesView.Process(op_list);
      if(waitForEntitiesView.Entities.find(to) != waitForEntitiesView.Entities.end()){
        waitingForEntities = false;
        // new thread(testTask, std::ref(connection), std::ref(rpcFutures));
        networkTester.startTests();
      }else if(waitForEntitiesView.Entities.size() % 100 == 1){
        cout << "\rgot " << waitForEntitiesView.Entities.size() << " entities" << endl;
      }
    }

    networkTester.processOpList(op_list);
    rpcFutures.processOpList(op_list);
    // networkWorker.processOpList(op_list);
    requestManager.processOpList(op_list);
  }


  // network::gotConnection(connection);

  cout << "Hello World!" << endl;
}

