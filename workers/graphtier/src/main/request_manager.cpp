#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <set>
#include <list>
#include <iterator>

#include "graphtier.h"
#include "request_job.h"
#include "request_manager.h"

using namespace worker;
using namespace worker::query;
using namespace std;
using namespace ::improbable::graphtier;

// Dirty Hacks as copy constructors not working for lists
namespace improbable {
  namespace graphtier {
    NodeDataData::NodeDataData(NodeDataData&& n){
      this->_networks = n.networks();
    }

    NetworkDataData::NetworkDataData(NetworkDataData&& n){
      this->_level = n.level();
      this->_nodes = n.nodes();
      this->_exit_node_sets = n.exit_node_sets();
    }
  }
}

namespace graphtier {
  namespace request {

    RequestManager::RequestManager(Connection& c): connection(c) {
      // dispatcher.OnEntityQueryResponse(&entityQueryResponse);
      // dispatcher.OnCommandRequest<NetworkGraphCommand::Commands::NetworkGraph>
        // (&NetworkWorker::networkGraphCommandRequest);

      dispatcher.OnEntityQueryResponse
        ([&](const EntityQueryResponseOp& op) {
          auto callback = entityRequestCallbacks[op.RequestId];
          entityRequestCallbacks.erase(op.RequestId);
          callback.job->recievedEntityQuery(callback, op);
        });

      dispatcher.OnCommandRequest<NodeCommands::Commands::FindRoute>
        ([&](const CommandRequestOp<NodeCommands::Commands::FindRoute>& op) {
          this->findRouteRequest(op);
        });
    }

    void RequestManager::processOpList(const OpList& op_list) {
      dispatcher.Process(op_list);
    }

    void RequestManager::addEntityRequestCallback(RequestId<EntityQueryRequest> requestId,
                                  RequestCallback callback){
      this->entityRequestCallbacksMtx.lock();
      this->entityRequestCallbacks[requestId] = callback;
      this->entityRequestCallbacksMtx.unlock();
    }


    void RequestManager::
    findRouteRequest(const CommandRequestOp
                     <NodeCommands::Commands::FindRoute>& op) {
      auto fromNodeId = op.EntityId;
      auto toNodeId = op.Request.to();

      cout << "request " << fromNodeId << " " << toNodeId << endl;

      auto job = new RequestJob(*this, fromNodeId, toNodeId);

      // List<Path_PathLeg> legs;
      // Path path(legs, 1);

      // Option<Path> pathOption(path);
      // NodeCommands::Commands::FindRoute::Response response(pathOption);


      // connection.SendCommandResponse<NodeCommands::Commands::FindRoute>
      //   (op.RequestId, response);



    }
  }
}
