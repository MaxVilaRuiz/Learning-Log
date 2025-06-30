let server = http.createServer(function(request, response) { // Create an instance of a web server application. The web server is saved in a variable "server"
    let body = "Hello World";
    // Handle the incoming message with an appropiate response
    response.writeHead(200, {
        'Content-Length': body.length,
        'Content-Type': 'text/plain'
    });
    response.end(body);
})

server.listen(8080); // After creating an instance of a server object, set the server to listen to a specific port