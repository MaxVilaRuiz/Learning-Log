// Def of Callback function:
// A function passed as an argument to another function
// Used to ensure an action is executed only after a result is produced

// Structure of callback functions
// http.request(options, [callback function]);

// Example
http.request(options, function(response){});


// Handling response events
http.request(options, function(response) {
    let buffer = '';

    // object.on() is a function that defines an event handler that the framework calls when an event occurs
    // Response object emits a 'data' event when Node.js module receives a part of the HTTP response message
    response.on('data',function(chunk) {
        buffer += chunk;
    })

    // When Node.js module receives the last part of the HTTP response message, the response object emits and 'end' event
    response.on('end',function() {
        console.log(buffer);
    })
}).end(); 


// Handling error events
let request = http.request(options,function(response){});
request.on('error',function(e){ // 'error' to emit the appropiate execution if an error has occurred
    resultCallback(e.message);
});
request.end(); 