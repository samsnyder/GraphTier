#include "graphtier.h"

#include <improbable/graphtier/NetworkGraphCommand.h>

namespace graphtier {
  namespace network {

    class NetworkWorker {
    public:
      NetworkWorker(Connection& connection);
      ~NetworkWorker() = default;

      void processOpList(const OpList& op_list);

    private:
      Dispatcher dispatcher;
      Connection& connection;


      void networkGraphCommandRequest(Connection& connection,
                                      const CommandRequestOp
                                      <NetworkGraphCommand::Commands::NetworkGraph>& op);

    };


  }
}
