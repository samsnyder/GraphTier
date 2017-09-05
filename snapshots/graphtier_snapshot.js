var snapshot = require("./generate.js");

var projectPath = "/Users/sam/dev/misc/GraphTier/spatial";

function nodeEntity(entityId, networks, position) {
    return {
        entity_id: entityId,
        prefab: "Node",
        entity_state: {
            "[schema.improbable.EntityAcl.component_extension]": snapshot.getAclSchema({
                readTags: ["graphtier", "visual"],
                write: [
                    {
                        componentId: 1000,
                        tags: ["graphtier"]
                    },
                    {
                        componentId: 8005,
                        tags: ["graphtier"]
                    },
                    {
                        componentId: 8006,
                        tags: ["graphtier"]
                    }
                ]
            }),
            "[schema.improbable.core.WorldTransform.component_extension]":
            snapshot.getWorldTransformSchema(position),
            "[schema.improbable.graphtier.NodeCommands.component_extension]": {},
            "[schema.improbable.graphtier.NodeData.component_extension]":
            snapshot.schemaObject({
                field1_networks: networks
            })
        }
    };
}

function networkEntity(entityId, nodesMap, sharedNetworkIds) {
    var nodes = [];
    for(id in nodesMap){
        nodes.push({
            field1_node_id: parseInt(id),
            field2_edges: nodesMap[id].map(function(edge){
                return {
                    field1_target_node_id: edge.to,
                    field2_cost: edge.cost
                };
            })
        })
    }
    return {
        entity_id: entityId,
        prefab: "Network",
        entity_state: {
            "[schema.improbable.EntityAcl.component_extension]": snapshot.getAclSchema({
                readTags: ["graphtier", "visual"],
                write: [
                    {
                        componentId: 1000,
                        tags: ["graphtier"]
                    },
                    {
                        componentId: 8002,
                        tags: ["graphtier"]
                    }
                ]
            }),
            "[schema.improbable.core.WorldTransform.component_extension]":
            snapshot.getWorldTransformSchema({
                x: 0,
                y: 0,
                z: 0
            }),
            "[schema.improbable.graphtier.NetworkData.component_extension]":
            snapshot.schemaObject({
                field1_nodes: nodes,
                field2_shared_networks: sharedNetworkIds
            })
        }
    };
}

function saveSnapshot(nodes, networks, snapshotPath, cb){
    var entities = nodes.concat(networks);
    snapshot.generateSnapshotBinary(entities, projectPath, snapshotPath, cb);
}


module.exports = {
    nodeEntity: nodeEntity,
    networkEntity: networkEntity,
    saveSnapshot: saveSnapshot
};
