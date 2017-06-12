#include "graphtier.h"



#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>



using namespace std;

namespace graphtier {
  namespace testing {

    class NetworkTester {
    public:
      NetworkTester(Connection& connection);
      ~NetworkTester() = default;

      void processOpList(const OpList& op_list);
      Connection& connection;



      void requestAllNetworks();
    private:
      Dispatcher dispatcher;

      RequestId<EntityQueryRequest> networkRequestId;
    };


  }
}
