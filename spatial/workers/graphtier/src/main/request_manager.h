#include "graphtier.h"

#include <map>

#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>



using namespace std;

namespace graphtier {
  namespace request {

    struct RequestCallback;

    class RequestManager {
    public:
      RequestManager(Connection& connection);
      ~RequestManager() = default;

      void processOpList(const OpList& op_list);
      Connection& connection;

      void addEntityRequestCallback(RequestId<EntityQueryRequest> requestId,
                                    RequestCallback callback);

      View view;

    private:

      mutex entityRequestCallbacksMtx;
      std::map<RequestId<EntityQueryRequest>, RequestCallback,
        RequestIdCompare<EntityQueryRequest>>
        entityRequestCallbacks;



      void findRouteRequest(const CommandRequestOp
                            <NodeCommands::Commands::FindRoute>& op);

    };


  }
}
