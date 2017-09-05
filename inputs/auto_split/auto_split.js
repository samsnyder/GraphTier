var dijkstra = require("./dijkstra.js");

function singleSource(network, source){
    var map = {};
    for(i in network.nodes){
        map[network.nodes[i]] = {};
    }

    for(i in network.edges){
        var edge = network.edges[i];
        if(edge.source in map){
            map[edge.source][edge.target] = edge.cost;
        }
    }

    return dijkstra.findPredecessors(map, source);
}

function minInObject(obj, ignore){
    var minVal = Infinity;
    var minKey = null;
    for(key in obj){
        if(key == ignore){
            continue;
        }
        if(obj[key] < minVal){
            minVal = obj[key];
            minKey = key;
        }
    }
    return minKey;
}

function generateVernough(network, higherNetwork, numNetworks){

    var nearestExitNodes = {};
    for(i in network.nodes){
        nearestExitNodes[network.nodes[i]] = {
            costs: {}
        };
    }
    // TODO: hack
    var numSkip = Math.floor(higherNetwork.nodes.length / numNetworks);
    for(var i=0; i<higherNetwork.nodes.length; i+=numSkip){
        var nodeId = higherNetwork.nodes[i];
        console.log("Computing for " + i, nodeId);
        var costs = singleSource(network, nodeId).costs;
        for(id in costs){
            nearestExitNodes[id].costs[nodeId] = costs[id];
            // if(costs[id] <= nearestExitNodes[id].cost){
            //     nearestExitNodes[id].exitNode = nodeId;
            //     nearestExitNodes[id].cost = costs[id];
            // }
        }
    }

    for(id in nearestExitNodes){
        var minExitNode = minInObject(nearestExitNodes[id].costs, -1);
        var secondMinExitNode = minInObject(nearestExitNodes[id].costs, minExitNode);
        nearestExitNodes[id].closestExitNode = minExitNode;
        nearestExitNodes[id].secondClosestExitNode = secondMinExitNode;
    }

    var inaccessibleNodes = [];
    for(i in network.nodes){
        if(Object.keys(nearestExitNodes[network.nodes[i]].costs).length == 0){
            inaccessibleNodes.push(network.nodes[i]);
        }
    }

    console.log(inaccessibleNodes.length + " inaccessible nodes");

    var exitNodeCounts = {};
    for(i in higherNetwork.nodes){
        exitNodeCounts[higherNetwork.nodes[i]] = 0;
    }
    for(id in nearestExitNodes){
        for(exitNodeId in nearestExitNodes[id]){
            exitNodeCounts
        }
        exitNodeCounts[nearestExitNodes[id].closestExitNode]++;
    }
    for(id in exitNodeCounts){
        if(exitNodeCounts[id] > 0){
            console.log(id, exitNodeCounts[id]);
        }
    }

    return nearestExitNodes;
}

function collapseSubNetworks(subNetworks, minSizeSubNetwork){
    for(id in subNetworks){
        if(subNetworks[id].nodes.length < minSizeSubNetwork){
            console.log("Collapse ", subNetworks[id].nodes.length);

            var smallestVal = Infinity;
            var mergeWithId = null;
            for(i in subNetworks[id].neighbours){
                var neighbourId = subNetworks[id].neighbours[i];
                if(!(neighbourId in subNetworks)){
                    continue;
                }
                if(subNetworks[neighbourId].nodes.length < smallestVal){
                    smallestVal = subNetworks[neighbourId].nodes.length;
                    mergeWithId = neighbourId;
                }
            }

            if(mergeWithId == null){
                console.log("No neighbour: ", subNetworks[id].neighbours);
                continue;
            }
            subNetworks[id].neighbours
                .splice(subNetworks[id].neighbours.indexOf(mergeWithId), 1);
            subNetworks[id].neighbours = subNetworks[id].neighbours
                .concat(subNetworks[mergeWithId].neighbours);
            subNetworks[id].exitNodes = subNetworks[id].exitNodes
                .concat(subNetworks[mergeWithId].exitNodes);
            subNetworks[id].nodes = subNetworks[id].nodes
                .concat(subNetworks[mergeWithId].nodes);
            delete subNetworks[mergeWithId];

            collapseSubNetworks(subNetworks, minSizeSubNetwork);
            return;
        }
    }
}

function splitNetwork(network, higherNetwork, numNetworks, minSizeSubNetwork){
    var nearestExitNodes = generateVernough(network, higherNetwork, numNetworks);

    var exitNodeSubNetworks = {};
    for(id in nearestExitNodes){
        var exitNodeId = nearestExitNodes[id].closestExitNode;
        var secondClosestExitNodeId = nearestExitNodes[id].secondClosestExitNode;
        if(exitNodeId == null){
            continue;
        }
        if(!(exitNodeId in exitNodeSubNetworks)){
            exitNodeSubNetworks[exitNodeId] = {
                neighbours: [],
                nodes: [],
                exitNodes: [exitNodeId]
            };
        }
        if(exitNodeSubNetworks[exitNodeId].neighbours.indexOf(secondClosestExitNodeId) < 0){
            exitNodeSubNetworks[exitNodeId].neighbours.push(secondClosestExitNodeId);
        }
        exitNodeSubNetworks[exitNodeId].nodes.push(id);
    }

    collapseSubNetworks(exitNodeSubNetworks, minSizeSubNetwork);

    for(id in exitNodeSubNetworks){
        // console.log(exitNodeSubNetworks[id]);
    }

    var subNetworks = [];
    for(id in exitNodeSubNetworks){
        subNetworks.push({
            exitNodes: exitNodeSubNetworks[id].exitNodes,
            nodes: exitNodeSubNetworks[id].nodes
        });
    }

    for(i in subNetworks){
        console.log("Sub network " + i,
                    subNetworks[i].nodes.length + " nodes",
                    subNetworks[i].exitNodes.length + " exit nodes");
    }

    return subNetworks;
}

module.exports = {
    splitNetwork: splitNetwork
};
