var osmium = require('osmium');
var fs = require("fs");
var auto_split = require("../../auto_split/auto_split.js");
var graphTierSnapshot = require("../../../snapshots/graphtier_snapshot.js");

var centre = {
    lat: 52.1875167,
    lon: 0.0966781
};

var metresPerDegree = {
    width: 1000,
    height: 1000
};

var currentEntityId = 1;
function newEntityId(){
    return currentEntityId++;
}

function loadOSM(fileName, highwayTags){
    var file = new osmium.File(fileName);
    var reader = new osmium.Reader(file);
    var handler = new osmium.Handler();

    var nodes = {};
    var ways = {};

    handler.on('node', function(node) {
        node.x = (node.lon - centre.lon) * metresPerDegree.width;
        node.y = (node.lat - centre.lat) * metresPerDegree.height
        node.entityId = newEntityId();
        nodes[node.id] = node;
    });

    handler.on('way', function(way) {
        if(!highwayTags || highwayTags.indexOf(way.tags("highway")) >= 0){
            way.node_refs = way.node_refs();
            way.maxSpeed = way.tags("maxspeed");
            ways[way.id] = way;
        }
    });

    osmium.apply(reader, handler);

    var nodeNeighbours = {};
    for(id in ways){
        for(var i=1; i<ways[id].node_refs.length; i++){
            var from = ways[id].node_refs[i-1];
            var to = ways[id].node_refs[i];

            if(!(from in nodeNeighbours)){
                nodeNeighbours[from] = {
                    incoming: [],
                    outgoing: []
                };
            }
            if(!(to in nodeNeighbours)){
                nodeNeighbours[to] = {
                    incoming: [],
                    outgoing: []
                };
            }
            nodeNeighbours[from].outgoing.push({
                nodeId: to,
                wayId: id,
                wayIndex: i
            });
            nodeNeighbours[to].incoming.push({
                nodeId: from,
                wayId: id,
                wayIndex: i-1
            });
        }
    }

    var nodesToRemove = [];

    for(id in ways){
        var noJuncUpTo = -1;
        for(var i = 1; i < ways[id].node_refs.length - 1; i++){
            if(nodeNeighbours[ways[id].node_refs[i]].incoming.length == 1 &&
               nodeNeighbours[ways[id].node_refs[i]].outgoing.length == 1){
                // No neighbours
            }else{
                noJuncUpTo = i - 1;
                break;
            }
        }
        if(noJuncUpTo < 0){
            noJuncUpTo = ways[id].node_refs.length - 2;
        }

        // console.log(noJuncUpTo, ways[id].node_refs);

        if(noJuncUpTo > 0){
            for(var i=1; i<=noJuncUpTo; i++){
                nodesToRemove.push(ways[id].node_refs[i]);
            }
            ways[id].node_refs.splice(1, noJuncUpTo);


            // console.log("\t", ways[id].node_refs);
        }


    }

    // for(id in nodeNeighbours){
    //     if(nodeNeighbours[id].incoming.length == 1 &&
    //        nodeNeighbours[id].outgoing.length == 1){
    //         nodesToRemove.push(id);

    //         var incoming = nodeNeighbours[id].incoming[0];
    //         var outgoing = nodeNeighbours[id].outgoing[0];

    //         // console.log("b", ways[outgoing.wayId].node_refs, outgoing.wayIndex);
    //         for(var k=0; k<ways[outgoing.wayId].node_refs.length - 1; k++){
    //             if(ways[outgoing.wayId].node_refs[k] == outgoing.nodeId){
    //                 ways[outgoing.wayId].node_refs.splice(k + 1, 1);
    //                 ways[outgoing.wayId].node_refs[k + 1] = incoming.nodeId;
    //             }
    //         }

    //         for(var k=1; k<ways[incoming.wayId].node_refs.length; k++){
    //             if(ways[incoming.wayId].node_refs[k] == incoming.nodeId){
    //                 ways[incoming.wayId].node_refs.splice(k - 1, 1);
    //                 ways[incoming.wayId].node_refs[k - 1] = incoming.nodeId;
    //             }
    //         }

    //         // ways[outgoing.wayId].node_refs.splice(outgoing.wayIndex + 1, 1);

    //         // if(outgoing.wayIndex + 1 < ways[outgoing.wayId].node_refs.length)
    //         // console.log("a", ways[outgoing.wayId].node_refs);

    //         // ways[incoming.wayId].node_refs.splice(incoming.wayIndex - 1, 1);
    //         // if(incoming.wayIndex - 1 >= 0)
    //             // ways[incoming.wayId].node_refs[incoming.wayIndex - 1] = outgoing.nodeId;

    //         // ways[neighbourA.wayId].splice(neighbourA.wayIndex, 0, item);

    //         // if(ways[neighbourA.wayId].node_refs[neighbourA.wayIndex + 1] == id){
    //         //     ways[neighbourA.wayId].node_refs[neighbourA.wayIndex + 1] = neighbourB.nodeId;
    //         // }
    //         // if(ways[neighbourB.wayId].node_refs[neighbourB.wayIndex + 1] == id){
    //         //     ways[neighbourB.wayId].node_refs[neighbourB.wayIndex + 1] = neighbourA.nodeId;
    //         // }
    //     }
    // }

    console.log("remove " + nodesToRemove.length);
    for(id in nodesToRemove){
        delete nodes[nodesToRemove[id]];
    }


    for(id in ways){
        var maxSpeed = ways[id].maxSpeed;
        if(maxSpeed == undefined){
            maxSpeed = 30;
        }else{
            maxSpeed = parseInt(maxSpeed.split(" ")[0]);
        }
        if(isNaN(maxSpeed)){
            maxSpeed = 30;
        }

        var edges = [];
        for(var i=1; i<ways[id].node_refs.length; i++){
            var from = nodes[ways[id].node_refs[i-1]];
            var to = nodes[ways[id].node_refs[i]];

            if(!(from.id in nodes) || !(to.id in nodes)){
                continue;
            }

            if(from == undefined || to == undefined){
                continue;
            }

            var distance = Math.sqrt(Math.pow(from.x - to.x, 2) + Math.pow(from.y - to.y, 2));
            var timeTaken = (distance / maxSpeed) * 3600;
            if(!timeTaken){
                // console.log(distance, maxSpeed, ways[id].tags("maxspeed"));
            }
            edges.push({
                source: from.id + "",
                target: to.id + "",
                cost: timeTaken
            });
            edges.push({
                source: to.id + "",
                target: from.id + "",
                cost: timeTaken
            });
        }
        ways[id].edges = edges;
    }

    return {
        nodes: nodes,
        ways: ways
    }
}



function extractNetwork(map){
    var nodeIds = Object.keys(map.nodes);

    var edges = [];
    for(id in map.ways){
        edges = edges.concat(map.ways[id].edges);
    }

    console.log("Network with " + nodeIds.length + " nodes");

    return {
        nodes: nodeIds,
        edges: edges
    }
}


function getGraphTierNetwork(map, level, networkType, higherNetworkIds){
    var nodeIds = map.nodes;
    var exitNodes = [];
    for(i in higherNodeIds){
        if(nodeIds.indexOf(higherNodeIds[i]) >= 0){
            exitNodes.push(higherNodeIds[i]);
        }
    }

    var edges = map.edges;

    console.log("Network with " + nodeIds.length + " nodes and " + exitNodes.length + " exit nodes.")

    return {
        x: 0,
        y: 0,
        z: 0,
        level: level,
        type: networkType,
        nodes: nodeIds,
        edges: edges,
        exitNodes: exitNodes
    }
}

function addNodeInfo(allNodes, map){
    for(id in map.nodes){
        allNodes[id] = {
            entityId: map.nodes[id].entityId,
            networks: [],
            position: {
                x: map.nodes[id].x,
                y: 0,
                z: map.nodes[id].y
            }
        };
    }
}

function getNodeMap(allNodes, nodeIds, edges){
    var nodeMap = {};
    for(i in nodeIds){
        nodeMap[allNodes[nodeIds[i]].entityId] = [];
    }
    for(i in edges){
        nodeMap[allNodes[edges[i].source].entityId].push({
            to: allNodes[edges[i].target].entityId,
            cost: edges[i].cost
        });
    }
    return nodeMap;
}

function addNetworkToNodes(allNodes, networkId, nodeIds){
    for(i in nodeIds){
        allNodes[nodeIds[i]].networks.push(networkId);
    }
}

// var allGraphOSM = loadOSM("data/cambridge_all.osm", ["residential", "unclassified"]);
// var mainGraphOSM = loadOSM("data/cambridge_main.osm", ["primary", "secondary", "trunk",

var name = "londonhigh";

var allGraphOSM = loadOSM("data/" + name + "_all.osm");
var mainGraphOSM = loadOSM("data/" + name + "_main.osm");
var highGraphOSM = loadOSM("data/" + name + "_high.osm");


var allNodes = {};
addNodeInfo(allNodes, allGraphOSM);

var allGraph = extractNetwork(allGraphOSM);
var mainGraph = extractNetwork(mainGraphOSM);
var highGraph = extractNetwork(highGraphOSM);


var topLevelEntityId = newEntityId();

var subNetworksIds = auto_split.splitNetwork(allGraph, mainGraph, 80, 1500);
var subNetworks = subNetworksIds.map(function(ids){
    var entityId = newEntityId();
    var nodeIds = ids.nodes;
    addNetworkToNodes(allNodes, entityId, nodeIds);
    var edges = [];
    for(i in allGraph.edges){
        var edge = allGraph.edges[i];
        if(nodeIds.indexOf(edge.source) >= 0 && nodeIds.indexOf(edge.target) >= 0){
            edges.push(edge);
        }
    }
    return {
        entityId: entityId,
        nodes: nodeIds,
        edges: edges,
        higherNetworkIds: [topLevelEntityId]
    }
    // return graphTierSnapshot.networkEntity(entityId,
    //                                        getNodeMap(allNodes, nodeIds, edges),
    //                                        [topLevelEntityId]);
});



addNetworkToNodes(allNodes, topLevelEntityId, mainGraph.nodes);
subNetworks.push({
    entityId: topLevelEntityId,
    nodes: mainGraph.nodes,
    edges: mainGraph.edges,
    higherNetworkIds: []
});

var subNetworkEntities = subNetworks.map(function(graph){
    return graphTierSnapshot.networkEntity(graph.entityId,
                                           getNodeMap(allNodes, graph.nodes, graph.edges),
                                           graph.higherNetworkIds);
});

return;

// subNetworks
// subNetworkEntities.push(
//     graphTierSnapshot.networkEntity(topLevelEntityId,
//                                     getNodeMap(allNodes, mainGraph.nodes, mainGraph.edges),
//                                     [])
// );


var nodeEntities = [];
for(id in allNodes){
    if(allNodes[id].entityId % 100 == 0 && allNodes[id].networks.length > 0){
        nodeEntities.push(graphTierSnapshot.nodeEntity(allNodes[id].entityId,
                                                       allNodes[id].networks,
                                                       allNodes[id].position));
    }
}

var resultObj = {
    nodes: allNodes,
    subNetworks: subNetworks
};
var jsonString = JSON.stringify(resultObj);
fs.writeFileSync("result.json", jsonString);




console.log("Last node id: " + nodeEntities[nodeEntities.length - 1].entity_id);

console.log("Num nodes: " + nodeEntities.length);

// subNetworks.push(getGraphTierNetwork(mainGraph, 1, "dijkstra", []))


graphTierSnapshot.saveSnapshot(nodeEntities, subNetworkEntities, "osm1.snapshot", console.log);

