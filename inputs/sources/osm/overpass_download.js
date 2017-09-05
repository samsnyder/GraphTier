var request = require('request');
var fs = require("fs");


// http://tools.geofabrik.de/calc/#type=geofabrik_standard&tab=1&places=4

var name = "londonhigh";
var bbox = "-0.1611 51.4439 0.0136 51.5512";

var bboxParts = bbox.split(" ");
var latBottom = bboxParts[1];
var latTop = bboxParts[3];
var lonLeft = bboxParts[0];
var lonRight = bboxParts[2];

var overpassBbox = latBottom + "," + lonLeft + "," + latTop + "," + lonRight;
// var overpassBbox = "52.12379295938503,-0.1138,52.27761095945195,0.27946472167968744";


var overpassUrl = "https://overpass-api.de/api/interpreter";

function parseQuery(query){
    return query.replace(new RegExp("{{bbox}}", 'g'), overpassBbox);
}

function requestOverpass(query, file, cb){
    request.post(
        overpassUrl,
        {
            form: {
                data: query
            }
        }
    ).on('error', function(err) {
        console.log(err)
    }).pipe(fs.createWriteStream(file))
        .on('finish', function(err){
            cb(err);
        });
}


var allNodesQuery = parseQuery(fs.readFileSync("queries/all_nodes.txt", "utf8"));
var mainNodesQuery = parseQuery(fs.readFileSync("queries/main_nodes.txt", "utf8"));
var highNodesQuery = parseQuery(fs.readFileSync("queries/high_nodes.txt", "utf8"));


requestOverpass(allNodesQuery, "data/" + name + "_all.osm", function(err){
    console.log("Downloaded all");
    requestOverpass(mainNodesQuery, "data/" + name + "_main.osm", function(err){
        console.log("Downloaded main");
        requestOverpass(highNodesQuery, "data/" + name + "_high.osm", function(err){
            console.log("Downloaded high");
        });
    });
});

