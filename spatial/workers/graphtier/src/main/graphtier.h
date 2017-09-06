#ifndef GRAPHTIER_H
#define GRAPHTIER_H


#include <improbable/worker.h>

#include <improbable/graphtier/NetworkData.h>

#include <improbable/graphtier/GraphTierTypes.h>

using namespace ::improbable::graphtier;

using namespace worker;

namespace graphtier {

  template <typename T>
    struct RequestIdCompare {
      bool operator()(const RequestId<T>& a, const RequestId<T>& b) const {
        return a.Id < b.Id;
      }
    };



  namespace request {
    class RequestManager;
    class RequestJob;


    struct RequestCallback {
      RequestJob* job;

      enum RequestCallbackType {
        MyAttachedNetworks,
        TargetAttachedNetworks,
        ReachableNetworks
      };

      RequestCallbackType callbackType;
    };


    struct Network {
      EntityId entityId;
      NetworkDataData networkData;

      int distFromMe = -1;
      int distFromTarget = -1;
      bool canReachCommon = false;
      bool checkedForCommon = false;

      Network(EntityId id, NetworkDataData& networkData);

      bool isCommon(){
        return distFromMe >= 0 && distFromTarget >= 0;
      }
    };




  }


}



#endif
