#include <chrono>
#include <thread>
#include <iostream>
#include <numeric>
#include <set>
#include <list>
#include <iterator>

#include "graphtier.h"
#include "request_job.h"
#include "pathfinding.h"
#include "request_manager.h"

using namespace worker;
using namespace worker::query;
using namespace std;
using namespace ::improbable::graphtier;


namespace graphtier {

  using namespace pathfinding;

  namespace request {

    ComponentId NODE_DATA_COMPONENT_ID = 8006;
    ComponentId NETWORK_DATA_COMPONENT_ID = 8002;

    Network::Network(EntityId id, NetworkDataData& networkData):
      entityId(id), networkData(networkData){
    }

    RequestJob::RequestJob(RequestManager& requestManager,
                           const EntityId fromEntityId,
                           const EntityId targetEntityId,
                           const RequestId
                           <IncomingCommandRequest<NodeCommands::Commands::FindRoute>>
                           requestId): requestManager(requestManager),
                                                       fromEntityId(fromEntityId),
                                                       targetEntityId(targetEntityId),
                                                       requestId(requestId){
      startTime = getTime();

      makeEntityRequest(fromEntityId, NODE_DATA_COMPONENT_ID,
                        RequestCallback::RequestCallbackType::MyAttachedNetworks);

      makeEntityRequest(targetEntityId, NODE_DATA_COMPONENT_ID,
                        RequestCallback::RequestCallbackType::TargetAttachedNetworks);
    }

    void RequestJob::makeEntityRequest(EntityId entityId,
                                       ComponentId componentId,
                                       RequestCallback::RequestCallbackType callbackType){
      auto entity = requestManager.view.Entities.find(entityId);
      if(entity != requestManager.view.Entities.end()){
        gotEntityFromRequest(entityId, entity->second, callbackType);
        return;
      }

      SnapshotResultType dataResultType{
        Option<List<ComponentId>>({componentId})
          };

      EntityQuery request = {
        EntityIdConstraint {entityId},
        dataResultType
      };
      auto requestId = requestManager.connection
        .SendEntityQueryRequest(request, Option<uint32_t>());

      auto callback = RequestCallback {
        this,
        callbackType
      };
      requestManager.addEntityRequestCallback(requestId, callback);
    }

    void RequestJob::recievedEntityQuery(RequestCallback& callback,
                                         const EntityQueryResponseOp& op){
      if(op.ResultCount != 1){
        this->errorProcessingJob("error getting entity state");
        return;
      }
      auto element = op.Result.begin();
      EntityId entityId = element->first;
      auto entity = element->second;

      gotEntityFromRequest(entityId, entity, callback.callbackType);
    }

    void RequestJob::gotEntityFromRequest(EntityId entityId, Entity& entity,
                                          RequestCallback::RequestCallbackType callbackType){
      switch(callbackType){
      case RequestCallback::RequestCallbackType::MyAttachedNetworks:
      case RequestCallback::RequestCallbackType::TargetAttachedNetworks:
        {
          auto nodeData = entity.Get<NodeData>();
          if(nodeData.empty()){
            this->errorProcessingJob("error getting entity state");
            return;
          }
          auto networks = nodeData->networks();
          this->attachedNetworksMtx.lock();
          switch(callbackType){
          case RequestCallback::RequestCallbackType::MyAttachedNetworks:
            myAttachedNetworks.insert(myAttachedNetworks.end(), networks.begin(),
                                      networks.end());
            break;
          case RequestCallback::RequestCallbackType::TargetAttachedNetworks:
            targetAttachedNetworks.insert(targetAttachedNetworks.end(), networks.begin(),
                                          networks.end());
            break;
          }
          this->attachedNetworksMtx.unlock();
          this->gotAttachedNetworks();
          break;
        }

      case RequestCallback::RequestCallbackType::ReachableNetworks:
        {
          auto networkData = entity.Get<NetworkData>();
          if(networkData.empty()){
            this->errorProcessingJob("error getting entity state: data empty");
            return;
          }
          this->recievedNetwork(entityId, *networkData);
          break;
        }
      }
    }

    void RequestJob::gotAttachedNetworks() {
      if(!this->myAttachedNetworks.empty() && !this->targetAttachedNetworks.empty()){
        attachedTime = getTime();

        for(auto const& networkId: this->myAttachedNetworks){
          networksToRequest.push(networkId);
        }

        for(auto const& networkId: this->targetAttachedNetworks){
          networksToRequest.push(networkId);
        }

        requestNetworks();
      }
    }

    void RequestJob::recievedNetwork(EntityId networkId, NetworkDataData& networkData){
      this->reachableMtx.lock();

      this->inFlightNetworks.erase(networkId);

      this->reachable.emplace(piecewise_construct,
                              forward_as_tuple(networkId),
                              forward_as_tuple(networkId, networkData));

      for(auto const &sharedNetworkId: networkData.shared_networks()){
        networksToRequest.push(sharedNetworkId);
      }

      if(requestingNetworks){
        this->reachableMtx.unlock();
      }else{
        this->reachableMtx.unlock();
        requestNetworks();
      }
    }

    void RequestJob::requestNetworks(){
      this->reachableMtx.lock();

      requestingNetworks = true;

      while(!networksToRequest.empty()){
        auto networkId = networksToRequest.top();
        networksToRequest.pop();

        if(this->inFlightNetworks.find(networkId) != this->inFlightNetworks.end() ||
           this->reachable.find(networkId) != this->reachable.end()){
          continue;
        }

        this->inFlightNetworks.insert(networkId);

        this->reachableMtx.unlock();
        makeEntityRequest(networkId, NETWORK_DATA_COMPONENT_ID,
                          RequestCallback::RequestCallbackType::ReachableNetworks);
        this->reachableMtx.lock();
      }

      requestingNetworks = false;

      if(this->networksToRequest.empty() && this->inFlightNetworks.empty()){
        this->reachableMtx.unlock();
        this->gotAllReachable();
      }else{
        this->reachableMtx.unlock();
      }

    }

    void RequestJob::markDistNetworks(EntityId networkId, int distFromMe,
                                      int distFromTarget){
      Network& network = this->reachable.find(networkId)->second;
      if(distFromMe >= 0){
        network.distFromMe =
          network.distFromMe < 0 ? distFromMe + 1 :
          min(network.distFromMe, distFromMe + 1);
      }
      if(distFromTarget >= 0){
        network.distFromTarget =
          network.distFromTarget < 0 ? distFromTarget + 1 :
          min(network.distFromTarget, distFromTarget + 1);
      }
      for(auto const& sharedNetworkId: network.networkData.shared_networks()){
        markDistNetworks(sharedNetworkId, network.distFromMe,
                              network.distFromTarget);
      }
    }

    bool RequestJob::canReachCommon(EntityId networkId){
      Network& network = this->reachable.find(networkId)->second;
      if(network.checkedForCommon){
        return network.canReachCommon;
      }
      bool canReach = network.isCommon();
      if(!canReach){
        for(auto const& sharedNetworkId: network.networkData.shared_networks()){
          if(canReachCommon(sharedNetworkId)){
            canReach = true;
            break;
          }
        }
      }
      network.canReachCommon = canReach;
      network.checkedForCommon = true;
      return canReach;
    }

    void RequestJob::gotAllReachable(){

      allReachableTime = getTime();

      for(auto const& id: this->myAttachedNetworks){
        markDistNetworks(id, 0, -1);
      }
      for(auto const& id: this->targetAttachedNetworks){
        markDistNetworks(id, -1, 0);
      }

      for(auto const& id: this->myAttachedNetworks){
        canReachCommon(id);
      }
      for(auto const& id: this->targetAttachedNetworks){
        canReachCommon(id);
      }

      // for(auto &networkPair : this->reachable){
      //   cout << "network: " << networkPair.second.entityId
      //        << " " << networkPair.second.distFromMe
      //        << " " << networkPair.second.distFromTarget
      //        << " " << networkPair.second.canReachCommon
      //        << endl;
      // }

      for (auto it = reachable.cbegin(); it != reachable.cend();){
        if(!it->second.canReachCommon){
          reachable.erase(it++);
        }else{
          ++it;
        }
      }

      PathFinding pathFinding(this->reachable);

      auto path = pathFinding.search(fromEntityId, targetEntityId);
      gotResult(path);
    }

    void RequestJob::errorProcessingJob(string const &message){
      cout << "Error processing job: " << message << endl;
      requestManager.connection.SendCommandFailure(requestId, message);

      delete this;
    }

    void RequestJob::gotResult(Option<Path>& path){
      RouteFindResponse response(path);
      requestManager.connection.SendCommandResponse(requestId, response);


      endTime = getTime();
      printTimes();

      delete this;
    }

    void RequestJob::printTimes(){
      cout << "whole time: " << getDuration(startTime, endTime) << endl << endl;
      cout << "toAttached: " << getDuration(startTime, attachedTime) << endl;
      cout << "toReachable: " << getDuration(attachedTime, allReachableTime) << endl;
      cout << "toDijkstra: " << getDuration(allReachableTime, endTime) << endl;
    }

  }
}
