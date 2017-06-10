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


  }


}



#endif
