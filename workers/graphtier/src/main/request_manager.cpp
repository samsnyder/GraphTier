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
      this->_nodes = n.nodes();
      this->_shared_networks = n.shared_networks();
    }

    Node::Node(Node&& n){
      this->_node_id = n.node_id();
      this->_edges = n.edges();
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

      auto job = new RequestJob(*this, fromNodeId, toNodeId, op.RequestId);

    }
  }
}
