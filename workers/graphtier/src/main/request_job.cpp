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


      // SnapshotResultType nodeDataResultType{
      //   Option<List<ComponentId>>({NODE_DATA_COMPONENT_ID})
      //     };

      // EntityQuery myNetworkRequest = {
      //   EntityIdConstraint {fromEntityId},
      //   nodeDataResultType
      // };
      // EntityQuery targetNetworkRequest = {
      //   EntityIdConstraint {targetEntityId},
      //   nodeDataResultType
      // };
      // // auto myId = requestManager.connection
      //   // .SendEntityQueryRequest(myNetworkRequest, Option<uint32_t>());
      // auto targetId = requestManager
      //   .connection.SendEntityQueryRequest(targetNetworkRequest, Option<uint32_t>());

      // auto myCallback = RequestCallback {
      //   this,
      //   RequestCallback::RequestCallbackType::MyAttachedNetworks
      // };
      // // requestManager.addEntityRequestCallback(myId, myCallback);

      // auto targetCallback = RequestCallback {
      //   this,
      //   RequestCallback::RequestCallbackType::TargetAttachedNetworks
      // };
      // requestManager.addEntityRequestCallback(targetId, targetCallback);
    }

    void RequestJob::makeEntityRequest(EntityId entityId,
                                       ComponentId componentId,
                                       RequestCallback::RequestCallbackType callbackType){
      cout << "request: " << requestManager.view.Entities.size() << endl;

      auto entity = requestManager.view.Entities.find(entityId);
      if(entity != requestManager.view.Entities.end()){
        cout << "found " << entityId << endl;
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

    // TODO: Use view to make this much faster
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
      cout << "entity req " << entityId << " " <<  callbackType << endl;
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
          for(int i=0; i<networks.size(); i++){
            switch(callbackType){
            case RequestCallback::RequestCallbackType::MyAttachedNetworks:
              myAttachedNetworks.push_back(networks[i]);
              break;
            case RequestCallback::RequestCallbackType::TargetAttachedNetworks:
              targetAttachedNetworks.push_back(networks[i]);
              break;
            }
          }
          this->attachedNetworksMtx.unlock();
          // switch(callback.callbackType){
          // case RequestCallback::RequestCallbackType::MyAttachedNetworks:
          //   this->myAttachedNetworks = Option<vector<EntityId>>(attachedNetworks);
          //   break;
          // case RequestCallback::RequestCallbackType::TargetAttachedNetworks:
          //   this->targetAttachedNetworks = Option<vector<EntityId>>(attachedNetworks);
          //   break;
          // }
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
          expandNetwork(networkId);
        }

        for(auto const& networkId: this->targetAttachedNetworks){
          expandNetwork(networkId);
        }
      }
    }

    void RequestJob::recievedNetwork(EntityId networkId, NetworkDataData& networkData){

      cout << "hh" << endl;
      this->reachableMtx.lock();

      this->inFlightNetworks.erase(networkId);

      Network network = Network::Network(networkId, networkData);
      this->reachable.insert({network.entityId, network});
      for(auto const &sharedNetworkId: networkData.shared_networks()){
        this->reachableMtx.unlock();
        expandNetwork(sharedNetworkId);
        this->reachableMtx.lock();
      }
      cout << "hhaa" << endl;

      if(this->inFlightNetworks.empty()){
        this->gotAllReachable();
      }

      this->reachableMtx.unlock();
    }

    void RequestJob::expandNetwork(EntityId networkId){
      cout << "ccaa" << endl;
      this->reachableMtx.lock();
      if(this->inFlightNetworks.find(networkId) != this->inFlightNetworks.end() ||
         this->reachable.find(networkId) != this->reachable.end()){
        this->reachableMtx.unlock();
        return;
      }

      this->inFlightNetworks.insert(networkId);
      cout << "ccddaa" << endl;


      this->reachableMtx.unlock();

      makeEntityRequest(networkId, NETWORK_DATA_COMPONENT_ID,
                        RequestCallback::RequestCallbackType::ReachableNetworks);
      cout << "cceeaa" << endl;

      // SnapshotResultType networkDataResultType{
      //   Option<List<ComponentId>>({NETWORK_DATA_COMPONENT_ID})
      //     };

      // EntityQuery request = {
      //   EntityIdConstraint {networkId},
      //   networkDataResultType
      // };
      // auto requestId = requestManager.connection
      //   .SendEntityQueryRequest(request, Option<uint32_t>());

      // auto callback = RequestCallback {
      //   this,
      //   RequestCallback::RequestCallbackType::ReachableNetworks
      // };
      // requestManager.addEntityRequestCallback(requestId, callback);

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
      // int newDistFromMe = -1;
      // if(distFromMe >= 0 &&
      //    (network.distFromMe < 0 || distFromMe < network.distFromMe)){
      //   network.distFromMe = distFromMe;
      //   newDistFromMe = distFromMe + 1
      // }
      // if(distFromTarget >= 0 &&
      //    (network.distFromTarget < 0 || distFromTarget < network.distFromTarget)){
      //   network.distFromTarget = distFromTarget;
      // }
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
      // TODO: Lock?

      cout << "all reach " << reachable.size() << endl;

      allReachableTime = getTime();

      // TODO: Remove non used
      for(auto const& id: this->myAttachedNetworks){
        markDistNetworks(id, 0, -1);
      }
      for(auto const& id: this->targetAttachedNetworks){
        markDistNetworks(id, -1, 0);
      }
      cout << "aabbll reach" << endl;

      for(auto const& id: this->myAttachedNetworks){
        canReachCommon(id);
      }
      for(auto const& id: this->targetAttachedNetworks){
        canReachCommon(id);
      }
      cout << "aall reach" << endl;

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
