var exec = require('child_process').exec;
var fs = require("fs");
var os = require("os");
var StringBuilder = require('stringbuilder');

function schemaObject(schema){
    for(key in schema){
        if(Array.isArray(schema[key])){
            var arrayKey = key;
            var array = schema[key];
            delete schema[key];
            for(i in array){
                schema[arrayKey + "_array" + i] = schemaObject(array[i]);
            }
        }else if(typeof(schema[key]) == "object"){
            schema[key] = schemaObject(schema[key]);
        }
    }

    return schema;
}



function generateEntityString(entity){
    var json = JSON.stringify(entity, null, 2);
    json = json
        .replace(/\"([^(\")"]+)\":/g,"$1:")
        .replace(/: {/g," {")
        .replace(/_array[0-9]+/g,"")
        .replace(/,\n/g,"\n");
    json = json.replace(/\n/g, "\n  ");

    json = "entity " + json + "\n";
    return json;
}

function getAclSchema(acl){
    var schema = {
        "field1_read_acl": {
            "field1_attribute_set": acl.readTags.map(function(tag){
                return {
                    "field1_attribute": tag
                }
            })
        },
        "field2_component_write_acl": acl.write.map(function(obj){
                return {
                    key: obj.componentId,
                    value: {
                        "field1_attribute_set": obj.tags.map(function(tag){
                            return {
                                "field1_attribute": tag
                            }
                        })
                    }
                }
            })
    };

    return schemaObject(schema);
}

function getPositionSchema(position){
    var schema = {
        field1_coords: {
            field1_x: position.x,
            field2_y: position.y,
            field3_z: position.z,
        }
    };
    return schemaObject(schema);
}

function generateSnapshotBinary(entities, projectPath, filePath, cb){
    var tempFilePath = os.tmpdir() + "/temp.snapshot.txt";
    console.log("Saving to " + tempFilePath);
    var file = fs.createWriteStream(tempFilePath);
    for(i in entities){
        var entityString = generateEntityString(entities[i]);
        file.write(entityString);
    }
    file.end();

    var scriptFile = projectPath + "/snapshots/convert_snapshot.sh";

    exec(scriptFile + " " + tempFilePath + " " + filePath, function(error, stdout, stderr) {
        console.log(error, stdout, stderr);
        console.log("snapshot writtent to " + filePath);
        if(cb) cb();
    });
}

module.exports = {
    generateSnapshotBinary: generateSnapshotBinary,
    schemaObject: schemaObject,
    getAclSchema: getAclSchema,
    getPositionSchema: getPositionSchema
};

// var entities = [
//     {
//         entity_id: 1,
//         prefab: "PlayerCreator",
//         entity_state: {
//             "[schema.improbable.EntityAcl.component_extension]": {
//                 field1_read: {
//                     field1_attribute_set_array0: {
//                         field1_attribute: {
//                             field1_name: "physics"
//                         }
//                     },
//                     field1_attribute_set_array17: {
//                         field1_attribute: {
//                             field1_name: "visual"
//                         }
//                     }
//                 },
//                 field2_component_acl: {
//                     field1_write_array0: {
//                         key: 1004,
//                         value: {
//                             field1_attribute_set: {
//                                 field1_attribute: {
//                                     field1_name: "physics"
//                                 }
//                             }
//                         }
//                     },
//                     field1_write_array1: {
//                         key: 1005,
//                         value: {
//                             field1_attribute_set: {
//                                 field1_attribute: {
//                                     field1_name: "physics"
//                                 }
//                             }
//                         }
//                     }
//                 }
//             },
//             "[schema.improbable.core.WorldTransform.component_extension]": {
//                 "field1_position": {
//                     x: 0,
//                     y: 0,
//                     z: 0
//                 },
//                 "field2_rotation": {
//                     field1_x: 0,
//                     field2_y: 0,
//                     field3_z: 0,
//                     field4_w: 0
//                 }
//             },
//             "[schema.improbable.core.PlayerCreation.component_extension]": {
//             },
//             "[schema.improbable.player.Test.component_extension]": {
//                 field1_timeout_beats_remaining: 104,
//                 field2_test_objs_array0: {
//                     field1_entity_ids_array0: 5,
//                     field1_entity_ids_array1: 6,
//                     field1_entity_ids_array2: 7,
//                 },
//                 field2_test_objs_array1: {
//                     field1_entity_ids_array0: 8,
//                     field1_entity_ids_array1: 9,
//                     field1_entity_ids_array2: 11,
//                 }
//             }
//         }
//     }
// ];


// var schemaTest = {
//     "field1_timeout_beats_remaining": 104,
//     "field2_test_objs": [
//         {
//             "field1_entity_ids": [5, 6, 7]
//         },
//         {
//             "field1_entity_ids": [8, 9, 11]
//         }
//     ],
//     "field3_position": {
//         x: 0,
//         y: 0,
//         z: 0,
//         "field2_test_objs": [
//             {
//                 "field1_entity_ids": [5, 6, 7]
//             },
//             {
//                 "field1_entity_ids": [8, 9, 11]
//             }
//         ]
//     }
// };

// var acl = {
//     readTags: ["physics", "visual"],
//     write: [
//         {
//             componentId: 1004,
//             tags: ["physics"]
//         },
//         {
//             componentId: 1005,
//             tags: ["physics"]
//         }
//     ]
// }

// console.log(JSON.stringify(schemaObject(getAclSchema(acl)), null, 4));

// // var schemaObj = schemaObject(schemaTest);

// // console.log(JSON.stringify(schemaObj, null, 4));

// var str = generateEntitiesString(entities);

// fs.writeFileSync("test.snapshot.txt", str);
