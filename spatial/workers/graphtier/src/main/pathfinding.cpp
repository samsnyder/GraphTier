#include <iostream>
#include <queue>
#include <stack>
#include <assert.h>

#include "pathfinding.h"

using namespace std;


namespace graphtier {
  namespace pathfinding {

    PathFinding::PathFinding(map<EntityId, Network>& networkMap){
      for(auto const&network: networkMap){
        for(auto const&node: network.second.networkData.nodes()){
          auto nodeId = node.node_id();
          GraphNode& graphNode = this->nodeMap[nodeId];
          graphNode.nodeId = nodeId;
          graphNode.nodeObjs.push_back({network.second.entityId, &node});
        }
      }
    }

    Option<Path> PathFinding::search(EntityId source, EntityId target){
      assert(this->nodeMap.find(source) != this->nodeMap.end());
      GraphNode& sourceNode = this->nodeMap[source];
      sourceNode.distance = 0;
      nodeQueue.push(&sourceNode);

      while(!nodeQueue.empty()){
        GraphNode* node = nodeQueue.top();
        nodeQueue.pop();
        // TODO: Prove this works, bit of a guess
        if(closed.find(node) != closed.end()){
          continue;
        }
        closed.insert(node);
        if(node->nodeId == target){
          break;
        }

        for(auto const& nodePair: node->nodeObjs){
          for(auto const& edge: nodePair.second->edges()){
            GraphNode& target = nodeMap[edge.target_node_id()];
            if(closed.find(&target) == closed.end()){
              double score = node->distance + edge.cost();

              if(target.distance >= score){
                target.distance = score;
                target.predecessor = node;
                target.edgeToPredNetworkId = nodePair.first;
                nodeQueue.push(&target);
              }
            }
          }
        }
      }

      return extractPath(source, target);
    }

    Option<Path> PathFinding::extractPath(EntityId from, EntityId to){
      GraphNode* currentNode = &nodeMap[to];
      double totalCost = currentNode->distance;
      stack<Path_PathLeg> pathLegs;
      while(currentNode != NULL){
        auto pred = currentNode->predecessor;
        if(pred != NULL){
          double cost = currentNode->distance - pred->distance;
          Path_PathLeg leg(pred->nodeId, currentNode->nodeId,
                           currentNode->edgeToPredNetworkId, cost);
          pathLegs.push(leg);
        }
        currentNode = pred;
      }
      if(pathLegs.empty() || pathLegs.top().from() == from){
        List<Path_PathLeg> legs;
        while(!pathLegs.empty()){
          legs.emplace_back(pathLegs.top());
          pathLegs.pop();
        }
        Path path(legs, totalCost);
        return Option<Path>(path);
      }else{
        return Option<Path>();
      }
    }
  }
}
