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

    ComponentId NODE_DATA_COMPONENT_ID = 8006;
    ComponentId NETWORK_DATA_COMPONENT_ID = 8002;

    Network::Network(EntityId id, NetworkDataData& networkData):
      entityId(id), networkData(networkData){
    }

    RequestJob::RequestJob(RequestManager& requestManager,
                           const EntityId fromEntityId,
                           const EntityId targetEntityId): requestManager(requestManager),
                                                           fromEntityId(fromEntityId),
                                                           targetEntityId(targetEntityId){
      SnapshotResultType nodeDataResultType{
        Option<List<ComponentId>>({NODE_DATA_COMPONENT_ID})
          };

      EntityQuery myNetworkRequest = {
        EntityIdConstraint {fromEntityId},
        nodeDataResultType
      };
      EntityQuery targetNetworkRequest = {
        EntityIdConstraint {targetEntityId},
        nodeDataResultType
      };
      auto myId = requestManager.connection
        .SendEntityQueryRequest(myNetworkRequest, Option<uint32_t>());
      auto targetId = requestManager
        .connection.SendEntityQueryRequest(targetNetworkRequest, Option<uint32_t>());

      auto myCallback = RequestCallback {
        this,
        RequestCallback::RequestCallbackType::MyAttachedNetworks
      };
      requestManager.addEntityRequestCallback(myId, myCallback);

      auto targetCallback = RequestCallback {
        this,
        RequestCallback::RequestCallbackType::TargetAttachedNetworks
      };
      requestManager.addEntityRequestCallback(targetId, targetCallback);
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


      switch(callback.callbackType){
      case RequestCallback::RequestCallbackType::MyAttachedNetworks:
      case RequestCallback::RequestCallbackType::TargetAttachedNetworks:
        {
          auto nodeData = entity.Get<NodeData>();
          if(nodeData.empty()){
            this->errorProcessingJob("error getting entity state");
            return;
          }
          auto networks = nodeData->networks();
          vector<EntityId> attachedNetworks;
          for(int i=0; i<networks.size(); i++){
              // auto network = Network {
              //   *networks[i].network(),
              //   (NetworkLevel) i,
              //   Option<vector<Network*>>()
              // };
            attachedNetworks.push_back(networks[i]);
          }
          this->attachedNetworksMtx.lock();
          switch(callback.callbackType){
          case RequestCallback::RequestCallbackType::MyAttachedNetworks:
            this->myAttachedNetworks = Option<vector<EntityId>>(attachedNetworks);
            break;
          case RequestCallback::RequestCallbackType::TargetAttachedNetworks:
            this->targetAttachedNetworks = Option<vector<EntityId>>(attachedNetworks);
            break;
          }
          this->gotAttachedNetworks();
          this->attachedNetworksMtx.unlock();
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

          // Network network = Network::Network(entityId, *networkData);

          // auto sharedNetworks = networkData->shared_networks();
          // // auto exitNodeSets = networkData->exit_node_sets();

          // this->reachableMtx.lock();

          // this->reachableMtx.unlock();
          // // auto forTarget =
          // //   callback.callbackType == RequestCallback::RequestCallbackType::TargetReachableNetworks;
          // // vector<Network>* reachable;
          // // if(forTarget){
          // //   reachable = &this->targetReachable;
          // //   this->targetReachableMtx.lock();
          // // }else{
          // //   reachable = &this->myReachable;
          // //   this->myReachableMtx.lock();
          // // }

          // // Network* expandingNetwork = NULL;
          // // for(vector<Network>::iterator it = reachable->begin();
          // //     it != reachable->end(); ++it){
          // //   if(it->entityId == entityId){
          // //     expandingNetwork = &(*it);
          // //   }
          // // }
          // // if(expandingNetwork == NULL){
          // //   this->errorProcessingJob("error getting entity state");
          // //   return;
          // // }

          // auto expandingNetwork = this->reachable.find(entityId);
          // if(expandingNetwork == this->reachable.end()){
          //   this->errorProcessingJob("error getting entity state: no network in map");
          //   return;
          // }

          // expandingNetwork->second.recieved = true;
          // for(int i=0; i<sharedNetworks.size(); i++){
          //   Network network(sharedNetworks[i]);
          //   if(expandingNetwork->second.reachableFromMe){
          //     network.reachableFromMe = true;
          //   }
          //   if(expandingNetwork->second.reachableFromTarget){
          //     network.reachableFromTarget = true;
          //   }
          //   this->reachable.insert({network.entityId, network});
          //   // reachable[network.entityId] = network;

          //   expandingNetwork->second.sharedNetworks.push_back(network.entityId);
          // }



          // if(forTarget){
          //   this->targetReachableMtx.unlock();
          // }else{
          //   this->myReachableMtx.unlock();
          // }

          // this->expandReachable();
          break;
        }
      }
    }

    void RequestJob::gotAttachedNetworks() {
      if(!this->myAttachedNetworks.empty() && !this->targetAttachedNetworks.empty()){
        cout << "Got attachedNetworks" << endl;
        for(auto const& networkId: *this->myAttachedNetworks){
          expandNetwork(networkId);
        }

        for(auto const& networkId: *this->targetAttachedNetworks){
          expandNetwork(networkId);
        }

        // this->toExpandMtx.lock();
        // for(std::vector<EntityId>::iterator it = this->myAttachedNetworks->begin();
        //     it != this->myAttachedNetworks->end(); ++it) {
        //   this->toExpand.push(*it);
        // }

        // for(std::vector<EntityId>::iterator it = this->targetAttachedNetworks->begin();
        //     it != this->targetAttachedNetworks->end(); ++it) {
        //   this->toExpand.push(*it);
        // }
        // this->toExpandMtx.unlock();

        // this->expandReachable();
      }
    }

    void RequestJob::recievedNetwork(EntityId networkId, NetworkDataData& networkData){
      cout << "recieved " << networkId << endl;

      this->reachableMtx.lock();

      this->inFlightNetworks.erase(networkId);

      Network network = Network::Network(networkId, networkData);
      this->reachable.insert({network.entityId, network});
      for(auto const &sharedNetworkId: networkData.shared_networks()){
        cout << "shared " << sharedNetworkId << endl;
        this->reachableMtx.unlock();
        expandNetwork(sharedNetworkId);
        this->reachableMtx.lock();
      }

      if(this->inFlightNetworks.empty()){
        this->gotAllReachable();
      }

      this->reachableMtx.unlock();
    }

    void RequestJob::expandNetwork(EntityId networkId){
      this->reachableMtx.lock();
      if(this->inFlightNetworks.find(networkId) != this->inFlightNetworks.end() ||
         this->reachable.find(networkId) != this->reachable.end()){
        this->reachableMtx.unlock();
        return;
      }

      this->inFlightNetworks.insert(networkId);
      cout << "expanding " << networkId << endl;
      SnapshotResultType networkDataResultType{
        Option<List<ComponentId>>({NETWORK_DATA_COMPONENT_ID})
          };

      EntityQuery request = {
        EntityIdConstraint {networkId},
        networkDataResultType
      };
      auto requestId = requestManager.connection
        .SendEntityQueryRequest(request, Option<uint32_t>());

      auto callback = RequestCallback {
        this,
        RequestCallback::RequestCallbackType::ReachableNetworks
      };
      requestManager.addEntityRequestCallback(requestId, callback);

      this->reachableMtx.unlock();
    }

    // TODO: fix sent request behaviour
    void RequestJob::expandReachable(){
      // vector<Network>* reachable;
      // if(forTarget){
      //   reachable = &this->targetReachable;
      //   this->targetReachableMtx.lock();
      // }else{
      //   reachable = &this->myReachable;
      //   this->myReachableMtx.lock();
      // }


      // this->toExpandMtx.lock();


      // bool hasNotRecieved = false;
      // for(auto &networkPair : this->reachable){
      // // for(std::vector<Network>::iterator it = this->reachable.begin();
      //     // it != this->reachable.end(); ++it) {
      //   if(!networkPair.second.recieved){
      //     hasNotRecieved = true;
      //   }
      //   if(!networkPair.second.requested){
      //     SnapshotResultType networkDataResultType{
      //       Option<List<ComponentId>>({NETWORK_DATA_COMPONENT_ID})
      //         };

      //     EntityQuery request = {
      //       EntityIdConstraint {networkPair.second.entityId},
      //       networkDataResultType
      //     };
      //     auto requestId = requestManager.connection
      //       .SendEntityQueryRequest(request, Option<uint32_t>());

      //     auto callback = RequestCallback {
      //       this,
      //       RequestCallback::RequestCallbackType::ReachableNetworks
      //     };
      //     requestManager.addEntityRequestCallback(requestId, callback);
      //     networkPair.second.requested = true;
      //   }
      // }

      // this->toExpandMtx.unlock();

      // if(!hasNotRecieved){
      //   this->gotAllReachable();
      // }


    }

    void RequestJob::gotAllReachable(){
      // TODO: Lock?
      cout << "got all reachable! " << this->reachable.size() << endl;


      for(auto &networkPair : this->reachable){
        cout << "networK: " << networkPair.second.entityId << " " << networkPair.second.reachableFromMe
             << " " << networkPair.second.reachableFromTarget << endl;
      }
      // vector<Network*> commonNetworks;
      // TODO: better intersection
      // for(vector<Network>::iterator myIt = this->myReachable.begin();
      //     myIt != this->myReachable.end(); myIt++){
      //   for(vector<Network>::iterator targetIt = this->targetReachable.begin();
      //       targetIt != this->targetReachable.end(); targetIt++){
      //     if(myIt->entityId == targetIt->entityId){
      //       cout << "common network " << myIt->entityId << endl;
      //       // commonNetworks.push_back(&(*myIt));
      //     }
      //   }
      // }
    }

    void RequestJob::errorProcessingJob(string const &message){
      cout << "Error processing job: " << message << endl;
    }


  }
}
