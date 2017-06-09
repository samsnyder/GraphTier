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

    Network::Network(EntityId id): entityId(id), requested(false){
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
            if(!networks[i].network().empty()){
              // auto network = Network {
              //   *networks[i].network(),
              //   (NetworkLevel) i,
              //   Option<vector<Network*>>()
              // };
              attachedNetworks.push_back(*networks[i].network());
            }
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

      case RequestCallback::RequestCallbackType::MyReachableNetworks:
      case RequestCallback::RequestCallbackType::TargetReachableNetworks:
        {
          auto networkData = entity.Get<NetworkData>();
          if(networkData.empty()){
            this->errorProcessingJob("error getting entity state");
            return;
          }
          auto exitNodeSets = networkData->exit_node_sets();

          auto forTarget =
            callback.callbackType == RequestCallback::RequestCallbackType::TargetReachableNetworks;
          vector<Network>* reachable;
          if(forTarget){
            reachable = &this->targetReachable;
            this->targetReachableMtx.lock();
          }else{
            reachable = &this->myReachable;
            this->myReachableMtx.lock();
          }

          Network* expandingNetwork = NULL;
          for(vector<Network>::iterator it = reachable->begin();
              it != reachable->end(); ++it){
            if(it->entityId == entityId){
              expandingNetwork = &(*it);
            }
          }
          if(expandingNetwork == NULL){
            this->errorProcessingJob("error getting entity state");
            return;
          }


          for(int i=0; i<exitNodeSets.size(); i++){
            Network network(exitNodeSets[i].network_id());
            reachable->push_back(network);

            expandingNetwork->exitNodeSets.push_back(&(*(--reachable->end())));
          }

          if(forTarget){
            this->targetReachableMtx.unlock();
          }else{
            this->myReachableMtx.unlock();
          }

          this->expandReachable(forTarget);
          break;
        }
      }
    }

    void RequestJob::gotAttachedNetworks() {
      if(!this->myAttachedNetworks.empty() && !this->targetAttachedNetworks.empty()){
        cout << "Got attachedNetworks" << endl;
        for(std::vector<EntityId>::iterator it = this->myAttachedNetworks->begin();
            it != this->myAttachedNetworks->end(); ++it) {
          auto network = Network(*it);
          this->myReachable.push_back(network);
        }

        for(std::vector<EntityId>::iterator it = this->targetAttachedNetworks->begin();
            it != this->targetAttachedNetworks->end(); ++it) {
          auto network = Network(*it);
          this->targetReachable.push_back(network);
        }

        this->expandReachable(true);
        this->expandReachable(false);
      }
    }

    void RequestJob::expandReachable(bool forTarget){
      vector<Network>* reachable;
      if(forTarget){
        reachable = &this->targetReachable;
        this->targetReachableMtx.lock();
      }else{
        reachable = &this->myReachable;
        this->myReachableMtx.lock();
      }

      bool sentRequest = false;
      for(std::vector<Network>::iterator it = reachable->begin();
          it != reachable->end(); ++it) {
        if(!it->requested){
          SnapshotResultType networkDataResultType{
            Option<List<ComponentId>>({NETWORK_DATA_COMPONENT_ID})
              };

          EntityQuery request = {
            EntityIdConstraint {it->entityId},
            networkDataResultType
          };
          auto requestId = requestManager.connection
            .SendEntityQueryRequest(request, Option<uint32_t>());

          RequestCallback::RequestCallbackType callbackType;
          if(forTarget){
            callbackType = RequestCallback::RequestCallbackType::TargetReachableNetworks;
          }else{
            callbackType = RequestCallback::RequestCallbackType::MyReachableNetworks;
          }
          auto callback = RequestCallback {
            this,
            callbackType
          };
          requestManager.addEntityRequestCallback(requestId, callback);
          sentRequest = true;
          it->requested = true;
        }
      }

      if(!sentRequest){
        // finished getting reached
        if(forTarget){
          this->targetReachableFinished = true;
        }else{
          this->myReachableFinished = true;
        }
      }

      if(forTarget){
        this->targetReachableMtx.unlock();
      }else{
        this->myReachableMtx.unlock();
      }

      if(!sentRequest){
        this->gotAllReachable();
      }


    }

    void RequestJob::gotAllReachable(){
      // TODO: Lock?
      if(this->myReachableFinished && this->targetReachableFinished){
        cout << "got all reachable! " << this->myReachable.size() << " " << this->targetReachable.size() << endl;

        // vector<Network*> commonNetworks;
        // TODO: better intersection
        for(vector<Network>::iterator myIt = this->myReachable.begin();
            myIt != this->myReachable.end(); myIt++){
          for(vector<Network>::iterator targetIt = this->targetReachable.begin();
              targetIt != this->targetReachable.end(); targetIt++){
            if(myIt->entityId == targetIt->entityId){
              cout << "common network " << myIt->entityId << endl;
              // commonNetworks.push_back(&(*myIt));
            }
          }
        }
      }
    }

    void RequestJob::errorProcessingJob(string const &message){
      cout << "Error processing job: " << message << endl;
    }


  }
}
