#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <set>

#include "graphtier.h"
#include "network.h"
#include "rpc_futures.h"

using namespace worker;
using namespace std;
using namespace ::improbable::graphtier;

namespace graphtier {
  namespace network {

    NetworkWorker::NetworkWorker(Connection& c): connection(c) {
      // dispatcher.OnEntityQueryResponse(&entityQueryResponse);
      // dispatcher.OnCommandRequest<NetworkGraphCommand::Commands::NetworkGraph>
        // (&NetworkWorker::networkGraphCommandRequest);

      dispatcher.OnCommandRequest<NetworkGraphCommand::Commands::NetworkGraph>
        ([&](const CommandRequestOp<NetworkGraphCommand::Commands::NetworkGraph>& op) {
          this->networkGraphCommandRequest(this->connection, op);
        });
    }

    void NetworkWorker::processOpList(const OpList& op_list) {
      dispatcher.Process(op_list);
    }


    void NetworkWorker::
    networkGraphCommandRequest(Connection& connection,
                               const CommandRequestOp
                               <NetworkGraphCommand::Commands::NetworkGraph>& op) {
      auto fromNetworkId = op.EntityId;
      auto toNetworkId = op.Request.target_network_id();

      cout << "request " << fromNetworkId << " " << toNetworkId << endl;

      NetworkGraphCommand::Commands::NetworkGraph::Response response(50);

      connection.SendCommandResponse<NetworkGraphCommand::Commands::NetworkGraph>
        (op.RequestId, response);



    }
  }
}
