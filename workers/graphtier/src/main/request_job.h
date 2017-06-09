#include "graphtier.h"


#include <vector>
#include <mutex>

#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>

using namespace std;

namespace graphtier {
  namespace request {


    struct Network {
      EntityId entityId;
      bool requested;
      /* NetworkLevel level; */
      vector<Network*> exitNodeSets;

      Network(EntityId id);
    };

    class RequestJob {
    public:
      RequestJob(RequestManager& requestManager,
                 const EntityId fromEntityId,
                 const EntityId targetEntityId);
      ~RequestJob() = default;

      void recievedEntityQuery(RequestCallback& callback, const EntityQueryResponseOp& op);

      const EntityId fromEntityId = 10;
      const EntityId targetEntityId = 11;


    private:
      RequestManager& requestManager;

      enum State {
        WaitingForNodeNetworks,
        WaitingForExitNodeSets
      };

      void errorProcessingJob(string const &message);

      State state;

      mutex attachedNetworksMtx;
      Option<vector<EntityId>> myAttachedNetworks;
      Option<vector<EntityId>> targetAttachedNetworks;
      void gotAttachedNetworks();

      mutex myReachableMtx;
      mutex targetReachableMtx;
      vector<Network> myReachable;
      vector<Network> targetReachable;
      bool myReachableFinished = false;
      bool targetReachableFinished = false;
      void gotAllReachable();

      void expandReachable(bool forTarget);
    };

  }
}
