#ifndef GRAPHTIER_H
#define GRAPHTIER_H


#include <improbable/worker.h>

#include <improbable/graphtier/NetworkData.h>

#include <improbable/graphtier/GraphTierTypes.h>

using namespace ::improbable::graphtier;

using namespace worker;

namespace graphtier {

  using NetworkLevel = std::uint32_t;

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
      /* NetworkLevel level; */

      Network(EntityId id, NetworkDataData& networkData);

      /* Network (Network&&) = default; */
    };




  }


}



#endif
