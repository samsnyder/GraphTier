var exec = require('child_process').exec;
var fs = require("fs");
var async = require("async");
var JSONStream = require( "JSONStream" );

var maxDepth = 3;
var numNodesPerNetwork = 8;
var numExitNodes = 2;
var networkType = "dijkstra";




function getNetwork(nodeMap, edges, level, networkType, higherNodeIds){
    nodeIds = [];
    for(i in edges){
        if(nodeIds.indexOf(edges[i].source + "") < 0){
            nodeIds.push(edges[i].source + "");
        }
        if(nodeIds.indexOf(edges[i].target + "") < 0){
            nodeIds.push(edges[i].target + "");
        }
    };

    var exitNodes = [];
    for(i in higherNodeIds){
        if(nodeIds.indexOf(higherNodeIds[i]) >= 0){
            exitNodes.push(higherNodeIds[i]);
        }
    }

    for(i in edges){
        var sourcePos = nodeMap[edges[i].source];
        var destPos = nodeMap[edges[i].target];
        var scale = 1 + (maxDepth - level) * 0.3;
        var cost = scale * Math.sqrt(Math.pow(destPos.x - sourcePos.x, 2) + Math.pow(destPos.z - sourcePos.z, 2));
        edges[i].cost = cost;
        edges[i].source = edges[i].source + ""
        edges[i].target = edges[i].target + ""
    }



    // console.log("Network with " + nodeIds.length + " nodes and " + exitNodes.length + " exit nodes.")

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


function getRandomGraph(nodeIds, cb) {
    // setTimeout(function(){
    //     return cb(null, {
    //         nodes: nodeIds,
    //         edges: []
    //     });
    // }, 1);
    // return;

    exec("python random_connected_graph.py -p " + nodeIds.length, function(error, stdout, stderr) {
        var exp = "var result = " + stdout.replace(new RegExp("\\(", 'g'), "[").replace(new RegExp("\\)", 'g'), "]")
        eval(exp);
        var edges = result.map(function(e){
            return {source: nodeIds[e[0]], target: nodeIds[e[1]]}
        });
        var numRandomEdges = Math.ceil(nodeIds.length * 0.7);
        for(var i=0; i<numRandomEdges; i++){
            var source = nodeIds[Math.floor(Math.random()*nodeIds.length)];
            var target = nodeIds[Math.floor(Math.random()*nodeIds.length)];
            if(source == target){
                continue;
            }
            var found = false;
            for(var k=0; k<edges.length; k++){
                if((edges[k].source == source && edges[k].target == target) ||
                   (edges[k].target == source && edges[k].source == target)){
                    found = true;
                    break;
                }
            }
            if(!found){
                edges.push({
                    source: source,
                    target: target
                });
            }
        }

        var reverseEdges = edges.map(function(e){
            return {source: e.target, target: e.source};
        });

        // console.log(nodeIds.length, result.length, edges.length);

        cb(null, {
            nodes: nodeIds,
            edges: edges.concat(reverseEdges)
        });
    });
}

function addEdges(graph, numNodes, startNode, cb){
    getRandomGraph(numNodes, startNode, function(err, extraGraph){
        var newGraph = {
            nodes: graph.nodes.concat(extraGraph.nodes),
            edges: graph.edges.concat(extraGraph.edges)
        }
        cb(err, newGraph);
    })
}


var lastStart = 2000;

var lastNetworkId = 1;
function recursiveGraph(depth, numNodes, numExitNodes, higherNetworkIds, centreNodes, finalResult, cb){
    if(depth == 0){
        return cb(null, {
            nodes: centreNodes,
            edges: []
        });
    }

    var networkId = lastNetworkId++;

    var nodeIds = JSON.parse(JSON.stringify(centreNodes));
    var start = lastStart
    lastStart = start + numNodes;
    for(var i=0; i<numNodes - centreNodes.length; i++){
        nodeIds.push(start + i)
    }


    getRandomGraph(nodeIds, function(err, graph){
        if(!(depth in finalResult)){
            finalResult[depth] = [];
        }
        graph.higherNetworkIds = higherNetworkIds;
        graph.networkId = networkId;
        finalResult[depth].push(graph)

        var nodeGroups = [];
        for(var i=0; i<graph.nodes.length; i+=numExitNodes){
            nodeGroups.push(graph.nodes.slice(i, i + numExitNodes))
        }


        async.mapSeries(nodeGroups, function(nodeGroup, subCb){
            recursiveGraph(depth - 1, numNodes, numExitNodes, [networkId], nodeGroup, finalResult, subCb);
        }, function(err, results){
            cb(null, finalResult)
        })
    })
}

function spaceOutNodes(nodeMap, nodeIds, centre, size){
    var radius = size;
    for(var i=0; i<nodeIds.length; i++){
        var theta = i * (2 * Math.PI / (nodeIds.length))
        var x = radius * Math.cos(theta) + ((Math.random() - 0.5) * radius * 0.2);
        var z = radius * Math.sin(theta) + ((Math.random() - 0.5) * radius * 0.2);
        nodeMap[nodeIds[i]] = {
            x: centre.x + x,
            y: 0,
            z: centre.z + z
        }
    }
}


var finalResult = {};

var initialNodes = [];
for(var i=0; i<numExitNodes; i++){
    initialNodes.push(i);
}

function createSnapshot(mD, nNpN, nEN, nT, cb){

    maxDepth = mD;
    numNodesPerNetwork = nNpN;
    numExitNodes = nEN;
    networkType = nT;

    console.log("Creating graph: " + maxDepth + ", " + numNodesPerNetwork
                + ", " + numExitNodes);

    lastStart = 2100;
    lastNetworkId = 1;
    finalResult = {};
    initialNodes = [];
    for(var i=0; i<numExitNodes; i++){
        initialNodes.push(lastStart++);
    }

    recursiveGraph(maxDepth, numNodesPerNetwork, numExitNodes, [], initialNodes, finalResult, function(err, graphs){


        var nodeMap = {};
        nodeMap[2100] = {
            x: 0,
            y: 0,
            z: 0
        }
        for(var level=maxDepth; level > 0; level--){
            for(i in graphs[level]){
                var higherNode = graphs[level][i].nodes[0];
                var centre = nodeMap[higherNode];
                var otherNodes = JSON.parse(JSON.stringify(graphs[level][i].nodes))
                otherNodes.shift();
                spaceOutNodes(nodeMap, otherNodes, centre, 5 * Math.pow(3, level))
            }
        }

        // console.log(nodeMap);


        var networks = [];

        for(var level=maxDepth; level > 0; level--){
            for(i in graphs[level]){
                var higherNodes = graphs[level][i].nodes.slice(0, numExitNodes);
                for(var n=0; n<higherNodes.length; n++){
                    higherNodes[n] = higherNodes[n] + "";
                }
                var network = getNetwork(nodeMap, graphs[level][i].edges, networkType, higherNodes)
                networks.push(network);
            }
        }

        console.log(networks[0]);

        var result = {
            nodes: nodeMap,
            networks: networks
        };

        var totalNodes = 0;
        for(node in result.nodes){
            totalNodes++;
        }
        console.log("Num Nodes: " + totalNodes);

        var totalNetworks = 0;
        for(network in result.networks){
            totalNetworks++;
        }
        console.log("Num Networks: " + totalNetworks);


        var fileName = "random." + maxDepth + "." + numNodesPerNetwork
            + "." + numExitNodes + "." + networkType + ".snapshot";

        console.log("Writing to " + fileName);

        var nodeEntities = [];
        for(nodeId in nodeMap){
            var nodesNetworkIds = [];
            for(network in nodesNetworkIds){
                if(network.nodes.indexOf(nodeId) >= 0){
                    nodesNetworkIds.push(network.id);
                    break;
                }
            }
            var nodeEntity = graphTierSnapshot.nodeEntity(nodeId, nodesNetorkIds, nodeMap[nodeId])
            nodeEntities.push(nodeEntity);
        }
        console.log(networks);

        graphTierSnapshot.saveSnapshot(nodeEntities, networkEntities, fileName);

        cb();

    });
}

var combinations = [];
// for(var h=3; h<=3; h++){
//     for(var i=1; i<=5; i++){
//         var start = i;
//         if(i == 1){
//             start = 2;
//         }
//         for(var n=start; n<=25; n+=1){
//             console.log(h + " - " + i + " - " + n);
//             combinations.push({
//                 height: h,
//                 exitNodes: i,
//                 numNodes: n
//             });
//         }
//     }
// }

combinations = [{height: 3, exitNodes: 2, numNodes: 6}]
                // {height: 3, exitNodes: 4, numNodes: 9}]

var results = {};

async.eachSeries(combinations, function iteratee(item, callback) {
    createSnapshot(item.height, item.numNodes, item.exitNodes, "dijkstra", callback);
}, function done() {
    console.log("done");

    // var dataStr = JSON.stringify(results, null, 4);
    // console.log(dataStr);
    // fs.writeFileSync("data.json", dataStr);
});

// createInput(3, 10, 2, "dijkstra");

// var graph = {
//     nodes: [0],
//     edges: []
// };

// addEdges(graph, 4, 0, function(err, newGraph){
//     console.log(newGraph);
// })
