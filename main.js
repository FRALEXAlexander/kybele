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
	
	
		
	
	socket.on('setCountry', function (data){
		
		console.log(data);
		console.log(countrieIndex[data.country]);
		//io.emit("ESPsetCountry",data);
	});
	
		
});




app.get('/', function(req, res) {
    
	
	res.sendFile(path.join(__dirname + '/index.html'));
});

app.get('/control.html', function(req, res) {
    
	res.sendFile(path.join(__dirname + '/control.html'));
	
});


app.get('/js/socket.io.js', function(req, res) {
    
	res.sendFile(path.join(__dirname + '/js/socket.io.js'));
	
});


app.get('/style.css', function(req, res) {
    
	res.sendFile(path.join(__dirname + '/style.css'));
	
});
app.get('/logoearth.png', function(req, res) {
    
	res.sendFile(path.join(__dirname + '/logoearth.png'));
	
});



app.listen(2000);
