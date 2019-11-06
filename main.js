var express = require('express');
var app = express();
var socketApp = express();
var path = require('path');
var http = require('http');
var fs = require('fs');
	

var countrieIndex = JSON.parse(fs.readFileSync("index.json"));


var server = http.createServer(socketApp).listen(2200);
 

var io = require('socket.io').listen(server);

console.log("server started");


io.on('connection', function (socket) {
	
	console.log("connection");
	
	

    socket.on('setCountry', function (data) {

        console.log(data);
        console.log(countrieIndex[data.country]);

        data.length = countrieIndex[data.country].length;

        data.country = countrieIndex[data.country];


        io.emit("ESPsetCountry", data);
        console.log(data);
    });

	
		
});




app.use(express.static('./public'));

app.listen(2000);
