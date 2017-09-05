var exec = require('child_process').exec;
var fs = require("fs");
var async = require("async");
var graphTierSnapshot = require("../../../snapshots/graphtier_snapshot.js");

var currentEntityId = 1;
function newEntityId(){
    return currentEntityId++;
}

function randomGraphEdges(nodeIds){
    var edges = [];
    var currentNodeSet = [nodeIds[0]];

    for(var i=1; i<nodeIds.length; i++){
        var fromNode = currentNodeSet[Math.floor(Math.random() * currentNodeSet.length)];
        edges.push({from: fromNode, to: nodeIds[i]});
        edges.push({from: nodeIds[i], to: fromNode});
        currentNodeSet.push(nodeIds[i]);
    }

    return edges;
}

function graphTree(depth, numNodes, numExitNodes, exitNodes, higherNetworkIds){
    var networkId = newEntityId();

    var nodes = JSON.parse(JSON.stringify(exitNodes));
    while(nodes.length < numNodes){
        nodes.push(newEntityId());
    }

    var edges = randomGraphEdges(nodes);
    var nodeMap = {};
    for(i in nodes){
        nodeMap[nodes[i]] = [];
    }
    for(i in edges){
        nodeMap[edges[i].from].push({
            to: edges[i].to,
            cost: Math.pow(5, depth)
        });
    }

    var graph = {
        networkId: networkId,
        depth: depth,
        nodes: nodeMap,
        higherNetworkIds: higherNetworkIds
    };

    graph.children = [];
    if(depth > 1){
        var numChildren = Math.floor(numNodes / numExitNodes);
        for(var i=0; i<numChildren; i++){
            var childExitNodes = nodes.slice(i * numExitNodes, (i + 1) * numExitNodes);
            var childTree = graphTree(depth - 1, numNodes, numExitNodes,
                                      childExitNodes, [networkId]);
            graph.children.push(childTree);
        }
    }

    return graph;
}

var height = 3;
var numNodes = 15;
var numExitNodes = 1;

var graphTree = graphTree(height, numNodes, numExitNodes, [], []);


var networkEntities = [];
var allNodesMap = {};

function addTreeNetworks(tree){
    for(id in tree.nodes){
        if(!(id in allNodesMap)){
            allNodesMap[id] = {
                networks: []
            };
        }
        allNodesMap[id].networks.push(tree.networkId);
    }
    networkEntities.push(graphTierSnapshot.networkEntity(tree.networkId,
                                                         tree.nodes,
                                                         tree.higherNetworkIds));
    for(i in tree.children){
        addTreeNetworks(tree.children[i]);
    }
}
addTreeNetworks(graphTree);


var nodeEntities = [];
for(id in allNodesMap){
    if(id % 100 != 0){
        continue;
    }
    nodeEntities.push(
        graphTierSnapshot.nodeEntity(parseInt(id), allNodesMap[id].networks,
                                     {
                                         x: 0,
                                         y: 0,
                                         z: 0
                                     }));
}

function followFirstNetwork(tree){
    if(tree.children.length > 0){
        return followFirstNetwork(tree.children[0]);
    }else{
        return tree;
    }
}
function followLastNetwork(tree){
    if(tree.children.length > 0){
        return followLastNetwork(tree.children[tree.children.length-1]);
    }else{
        return tree;
    }
}

// console.log(nodeEntities[5]);

// console.log(JSON.stringify(graphTree, null, 4))

console.log("Number of nodes: " + nodeEntities.length);
console.log("Number of networks: " + networkEntities.length);

var firstNetwork = Object.keys(followFirstNetwork(graphTree).nodes);
var lastNetwork = Object.keys(followLastNetwork(graphTree).nodes);
console.log("From: " + firstNetwork[firstNetwork.length-1]);
console.log("To: " + lastNetwork[lastNetwork.length-1]);

graphTierSnapshot.saveSnapshot(nodeEntities, networkEntities, "random1.snapshot", console.log);
