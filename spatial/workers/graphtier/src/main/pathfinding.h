#include <iostream>
#include <queue>
#include <map>

#include "graphtier.h"

using namespace std;

namespace graphtier {

  using namespace request;

  namespace pathfinding {


    struct GraphNode {
      EntityId nodeId;
      double distance = numeric_limits<double>::infinity();
      GraphNode* predecessor = NULL;
      EntityId edgeToPredNetworkId = 0;
      vector<pair<EntityId, const Node*>> nodeObjs;
    };



    class PathFinding {
    public:

      PathFinding(map<EntityId, Network>& networkMap);

      Option<Path> search(EntityId from, EntityId to);

    private:

      double bestPathLength = numeric_limits<double>::infinity();

      map<EntityId, GraphNode> nodeMap;

      struct CmpGraphNode{
        bool operator()(const GraphNode* a, const GraphNode* b) const {
          return a->distance > b->distance;
        }
      };

      priority_queue<GraphNode*, vector<GraphNode*>, CmpGraphNode> nodeQueue;
      set<GraphNode*> closed;

      Option<Path> extractPath(EntityId from, EntityId to);
    };

  }
}
