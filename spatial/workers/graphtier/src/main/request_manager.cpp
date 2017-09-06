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

namespace graphtier {
  namespace request {

    RequestManager::RequestManager(Connection& c): connection(c) {
      view.OnEntityQueryResponse
        ([&](const EntityQueryResponseOp& op) {
          auto callback = entityRequestCallbacks.find(op.RequestId);
          if(callback != entityRequestCallbacks.end()){
            callback->second.job->recievedEntityQuery(callback->second, op);
            entityRequestCallbacks.erase(op.RequestId);
          }
        });

      view.OnCommandRequest<NodeCommands::Commands::FindRoute>
        ([&](const CommandRequestOp<NodeCommands::Commands::FindRoute>& op) {
          this->findRouteRequest(op);
        });
    }

    void RequestManager::processOpList(const OpList& op_list) {
      view.Process(op_list);
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

      auto job = new RequestJob(*this, fromNodeId, toNodeId, op.RequestId);

    }
  }
}
