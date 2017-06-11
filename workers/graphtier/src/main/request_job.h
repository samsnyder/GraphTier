#include "graphtier.h"


#include <vector>
#include <queue>
#include <chrono>
#include <mutex>

#include <improbable/graphtier/NodeCommands.h>
#include <improbable/graphtier/NodeData.h>

using namespace std;
using namespace std::chrono;

namespace graphtier {
  namespace request {


    class RequestJob {
    public:
      RequestJob(RequestManager& requestManager,
                 const EntityId fromEntityId,
                 const EntityId targetEntityId,
                 const RequestId<IncomingCommandRequest<NodeCommands::Commands::FindRoute>>
                 requestId);
      ~RequestJob() = default;

      void recievedEntityQuery(RequestCallback& callback, const EntityQueryResponseOp& op);

      const EntityId fromEntityId;
      const EntityId targetEntityId;


    private:
      const RequestId<IncomingCommandRequest<NodeCommands::Commands::FindRoute>>
      requestId;

      RequestManager& requestManager;

      enum State {
        WaitingForNodeNetworks,
        WaitingForExitNodeSets
      };

      void errorProcessingJob(string const &message);
      void gotResult(Option<Path>& path);

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

      void markDistNetworks(EntityId networkId, int distFromMe, int distFromTarget);

      time_point<high_resolution_clock> startTime;
      time_point<high_resolution_clock> attachedTime;
      time_point<high_resolution_clock> allReachableTime;
      time_point<high_resolution_clock> endTime;

      time_point<high_resolution_clock> getTime(){
        return std::chrono::high_resolution_clock::now();
      }
      void printTimes();
      double getDuration(time_point<high_resolution_clock> start, time_point<high_resolution_clock> finish){
        return std::chrono::duration_cast<duration<double>>(finish-start).count() * 1000;
      }
    };

  }
}
