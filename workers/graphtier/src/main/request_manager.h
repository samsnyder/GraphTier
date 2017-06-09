#include "graphtier.h"



#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>



using namespace std;

namespace graphtier {
  namespace request {

    struct RequestCallback;

    template <typename T>
    struct RequestIdCompare {
      bool operator()(const RequestId<T>& a, const RequestId<T>& b) const {
        return a.Id < b.Id;
      }
    };

    class RequestManager {
    public:
      RequestManager(Connection& connection);
      ~RequestManager() = default;

      void processOpList(const OpList& op_list);
      Connection& connection;

      void addEntityRequestCallback(RequestId<EntityQueryRequest> requestId,
                                    RequestCallback callback);

    private:
      Dispatcher dispatcher;

      mutex entityRequestCallbacksMtx;
      std::map<RequestId<EntityQueryRequest>, RequestCallback,
        RequestIdCompare<EntityQueryRequest>>
        entityRequestCallbacks;



      void findRouteRequest(const CommandRequestOp
                            <NodeCommands::Commands::FindRoute>& op);

    };


  }
}
