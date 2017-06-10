#include "graphtier.h"


#include <vector>
#include <queue>
#include <mutex>

#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>

using namespace std;

namespace graphtier {
  namespace request {


    struct Network {
      EntityId entityId;
      NetworkDataData networkData;

      bool reachableFromMe = false;
      bool reachableFromTarget = false;
      /* NetworkLevel level; */

      Network(EntityId id, NetworkDataData& networkData);

      /* Network (Network&&) = default; */
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

      /* mutex toExpandMtx; */
      /* queue<EntityId> toExpand; */

      mutex reachableMtx;
      set<EntityId> inFlightNetworks;
      void recievedNetwork(EntityId networkId, NetworkDataData& networkData);
      void expandNetwork(EntityId networkId);

      map<EntityId, Network> reachable;
      void gotAllReachable();

      void expandReachable();
    };

  }
}
