#include "graphtier.h"

#include <future>


#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>


#include "pathfinding.h"

using namespace std;

namespace graphtier {
  using namespace pathfinding;

  namespace testing {

    struct TestResult {
      EntityId from;
      EntityId to;
      double millis;
      Option<Path> path;
    };

    class NetworkTester {
    public:
      NetworkTester(Connection& connection);
      ~NetworkTester() = default;

      void processOpList(const OpList& op_list);
      Connection& connection;

      void startTests();

      void gotNetworks();

      void queueTest(EntityId from, EntityId to);

      pair<TestResult, TestResult> runTest(EntityId from, EntityId to);
      TestResult runGraphTierTest(EntityId from, EntityId to);
      TestResult runTraditionalTest(EntityId from, EntityId to);

      void requestAllNetworks();
    private:
      Dispatcher dispatcher;

      RequestId<EntityQueryRequest> networkRequestId;

      vector<EntityId> nodeIds;
      map<EntityId, Network> networkMap;
      queue<pair<EntityId, EntityId>> testQueue;

      map<RequestId<OutgoingCommandRequest<NodeCommands::Commands::FindRoute>>,
        shared_ptr<promise<const typename NodeCommands::Commands::FindRoute::Response>>,
        RequestIdCompare<OutgoingCommandRequest<NodeCommands::Commands::FindRoute>>>
        graphTierRequestMap;
    };


  }
}
