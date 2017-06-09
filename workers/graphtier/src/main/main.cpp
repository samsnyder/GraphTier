#include <improbable/worker.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <improbable/graphtier/NetworkCommands.h>


#include <improbable/graphtier/NodeCommands.h>

// #define BOOST_THREAD_PROVIDES_FUTURE
// #include <boost/thread.hpp>
// #include <boost/thread/future.hpp>



#include "graphtier.h"
#include "network.h"
#include "request_manager.h"
#include "rpc_futures.h"

using namespace worker;
using namespace std;

using namespace graphtier;

// EntityId networkId = -1;

// void RunEventLoop(worker::Connection& connection, worker::View& dispatcher) {
//   // static const unsigned kFramesPerSecond = 60;
//   // static const std::chrono::duration<double> kFramePeriodSeconds(1. / static_cast<double>(kFramesPerSecond));

//   // auto time = std::chrono::high_resolution_clock::now();

//   // cout << kFramePeriodSeconds.count() << endl;

//   EntityId waitForId = 1;

//   while (true) {
//     auto op_list = connection.GetOpList(0);
//     dispatcher.Process(op_list);

//     auto entity = dispatcher.Entities[waitForId];
//     auto data = entity.Get<NetworkCommands>();
//     if(!data.empty()){
//       break;
//     }


//     // Do other work here...

//     // cout << "Sending log" << endl;
//     // cout << connection.IsConnected() << endl;
//     // connection.SendLogMessage("logger", "hello");

//     // time = time + kFramePeriodSeconds;
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//   }
//   cout << "Got Id" << endl;

//   network::findCommonNetwork(1, 2);

//   while(true){
//     auto op_list = connection.GetOpList(0);
//     dispatcher.Process(op_list);
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//   }
// }


// void RegisterCallbacks(worker::View& dispatcher) {
//   // dispatcher.OnAddEntity([&](const worker::AddEntityOp& op) {
//   //     // Do something with op.EntityId
//   //     cout << "New Entity " << op.EntityId << endl;

//   //     networkId = op.EntityId;

//   //     // if(op.EntityId == 2){
//   //       auto entity = dispatcher.Entities[op.EntityId];
//   //       auto data = entity.Get<NetworkCommands>();

//   //       cout << data.empty() << endl;

//   //       // cout << data.position().z() << endl << endl;
//   //     // }
//   //   });

//   dispatcher.OnEntityQueryResponse([&](const EntityQueryResponseOp& op) {
//       cout << "entity query" << endl;
//     });
// }


// Dirty hack
void waitForNetworks(worker::Connection& connection) {
  View dispatcher;

  EntityId waitForId = 1;

  while (true) {
    auto op_list = connection.GetOpList(0);
    dispatcher.Process(op_list);

    auto entity = dispatcher.Entities[waitForId];
    auto data = entity.Get<NetworkCommands>();
    if(!data.empty()){
      break;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

// void runTestLoop(Connection& connection, RpcFutures& rpcFutures){
//   while (true) {
//     auto op_list = connection.GetOpList(10000);
//     rpcFutures.processOpList(op_list);

//     cout << "test loop" << endl;
//   }
// }

void testTask(Connection& connection, RpcFutures& rpcFutures)
{

  // Connection connection = *connectionPtr;


  // thread testThread(runTestLoop, std::ref(connection), ref(rpcFutures));

  std::this_thread::sleep_for(std::chrono::seconds(1));

  cout << "Sending request" << endl;

  NodeCommands::Commands::FindRoute::Request request(5);

  // connection.SendCommandRequest<NetworkGraphCommand::Commands::NetworkGraph>(1, request, Option<uint32_t>());

  auto f1 = rpcFutures.sendCommandRequest<NodeCommands::Commands::FindRoute>
    (connection, 4, request, Option<uint32_t>(5000));


  // auto f3 = rpcFutures.sendCommandRequest<NetworkGraphCommand::Commands::NetworkGraph>
    // (connection, 1, request, Option<uint32_t>(3000));



  f1.wait();
  // boost::wait_for_all(f1, f2);

  auto response = f1.get();
  if(!response.path().empty()){
    cout << "path successful: " << (*response.path()).cost() << endl;
  }else{
    cout << "no path found" << endl;
  }




  // f.wait();
  // cout << "before get" << endl;

  // try {
  //   auto resp = f.has_exception();
  //   cout << "got resp " << resp << endl;
  // } catch(const std::exception& e) {
  //   std::cerr << e.what() << endl;
  // }

  // code that could cause exception


  // std::thread _testThread{[f](future<NetworkGraphCommand::Commands::NetworkGraph::Response> _f) {
  //     auto resp = _f.get();
  //     cout << resp << endl;
  //   }, f};


}




int main(int argc, char** argv) {
  if (argc < 2 || 3 < argc) {
    return 1;
  }

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

  waitForNetworks(connection);

  RpcFutures rpcFutures;
  // network::NetworkWorker networkWorker(connection);
  request::RequestManager requestManager(connection);

  thread testThread(testTask, std::ref(connection), std::ref(rpcFutures));

  while (true) {
    auto op_list = connection.GetOpList(10000);
    rpcFutures.processOpList(op_list);
    // networkWorker.processOpList(op_list);
    requestManager.processOpList(op_list);
  }


  // network::gotConnection(connection);

  cout << "Hello World!" << endl;
}

