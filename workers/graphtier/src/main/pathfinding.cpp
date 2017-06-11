#include <iostream>
#include <queue>
#include <stack>

#include "pathfinding.h"

using namespace std;


namespace graphtier {
  namespace pathfinding {

    // bool operator <(const GraphNode* x, const GraphNode* y) {
      // return x->distance < y->distance;
    // }



    PathFinding::PathFinding(map<EntityId, Network>& networkMap){
      for(auto const&network: networkMap){
        for(auto const&node: network.second.networkData.nodes()){
          auto nodeId = node.node_id();
          GraphNode& graphNode = this->nodeMap[nodeId];
          graphNode.nodeId = nodeId;
          graphNode.nodeObjs.push_back(&node);
        }
      }
    }

    Option<Path> PathFinding::search(EntityId source, EntityId target){
      GraphNode& sourceNode = this->nodeMap[source];
      sourceNode.distance = 0;
      nodeQueue.push(&sourceNode);

      while(!nodeQueue.empty()){
        GraphNode* node = nodeQueue.top();
        nodeQueue.pop();
        closed.insert(node);

        for(auto const& nodePtr: node->nodeObjs){
          for(auto const& edge: nodePtr->edges()){
            GraphNode& target = nodeMap[edge.target_node_id()];
            if(closed.find(&target) == closed.end()){
              double score = node->distance + edge.cost();

              if(target.distance >= score){
                target.distance = score;
                target.predecessor = node;
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
          Path_PathLeg leg(pred->nodeId, currentNode->nodeId, 0, cost);
          pathLegs.push(leg);
        }
        currentNode = pred;
      }
      if(pathLegs.top().from() == from){
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


    // void PathFinding::search(EntityId source, EntityId target){
    //   if(source == target){
    //     // TODO: return unit path
    //     cout << "same node" << endl;
    //     return;
    //   }

    //   GraphNode& sourceNode = this->nodeMap[source];
    //   sourceNode.distance = 0;
    //   openA.push(&sourceNode);

    //   GraphNode& targetNode = this->nodeMap[target];
    //   targetNode.distance = 0;
    //   openB.push(&targetNode);

    //   while(!openA.empty() && !openB.empty()){
    //     double minimumPath = openA.top()->distance + openB.top()->distance;

    //     if(minimumPath >= bestPathLength){
    //       // TODO: return path
    //       cout << "path found" << endl;
    //       return;
    //     }

    //     if(openA.size() + closedA.size() < openB.size() + closedB.size()){
    //       expandForwards();
    //     }else{
    //       expandBackwards();
    //     }
    //   }

    // }

    // void PathFinding::expandForwards(){
    //   GraphNode* node = openA.top();
    //   openA.pop();

    //   closedA.insert(node);

    //   for(auto const& nodePtr: node->nodeObjs){
    //     for(auto const& edge: nodePtr->edges()){
    //       GraphNode& target = nodeMap[edge.target_node_id()];
    //       if(closedA.find(&target) == closedA.end()){
    //         double score = node->distance + edge.cost();

    //         if(target.distance >= score){
    //           target.distance = score;
    //           target.predecessor = node;
    //           openA.push(target);
    //         }
    //       }
    //     }
    //   }
    // }

    // void PathFinding::expandForwards(){
    //   GraphNode* node = openA.top();
    //   openA.pop();

    //   closedA.insert(node);

    //   for(auto const& nodePtr: node->nodeObjs){
    //     for(auto const& edge: nodePtr->edges()){
    //       GraphNode& target = nodeMap[edge.target_node_id()];
    //       if(closedA.find(&target) == closedA.end()){
    //         double score = node->distance + edge.cost();

    //         if(target.distance >= score){
    //           target.distance = score;
    //           target.predecessor = node;
    //           openA.push(target);
    //         }
    //       }
    //     }
    //   }
    // }

  }
}
