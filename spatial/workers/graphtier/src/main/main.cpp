#include <improbable/worker.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <improbable/graphtier/NetworkCommands.h>


#include <improbable/graphtier/NodeCommands.h>


#include "graphtier.h"
#include "request_manager.h"
#include "network_tester.h"
#include "rpc_futures.h"

using namespace worker;
using namespace std;

using namespace graphtier;

int main(int argc, char** argv) {
  // TODO: do args
  // if (argc < 2 || 3 < argc) {
    // return 1;
  // }


  EntityId from = atoi(argv[2]);
  EntityId to = atoi(argv[3]);

  worker::ConnectionParameters parameters;
  parameters.WorkerType = "graphtier";
  parameters.Network.ConnectionType = worker::NetworkConnectionType::kTcp;
  parameters.Network.UseExternalIp = false;

  const std::string workerId = argv[1];

  std::string hostname = "localhost";
  if (argc == 3) {
    hostname = argv[2];
  }

  worker::Connection connection = Connection::ConnectAsync(hostname, 7777, workerId, parameters).Get();

  RpcFutures rpcFutures;
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
        networkTester.startTests();
      }else if(waitForEntitiesView.Entities.size() % 100 == 1){
        cout << "\rgot " << waitForEntitiesView.Entities.size() << " entities" << endl;
      }
    }

    networkTester.processOpList(op_list);
    rpcFutures.processOpList(op_list);
    requestManager.processOpList(op_list);
  }
}

