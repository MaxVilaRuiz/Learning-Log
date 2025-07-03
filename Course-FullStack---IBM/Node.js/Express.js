// How Express works
// 1. Declare Express as a dependency in the package of Node.js project
//      Create a `package.json` file in your project
//      * Name: name for the Node.js module
//      * Version: version of the module
//      * Description: describes the purpose of the module
//      * Main: identifies the Node.js script as the entrypoint into the module
//      * Dependencies: list which Node.js modules the current module requires
//      Example
        const package =
        {
            "name": "temperature",
            "version": "1.0.0",
            "description": "Retrieve current weather",
            "main": "app.js",
            "dependencies": {
                "express": "4.x"
            }
        }

// 2. Run npm command to download any missing module
        // General case: `npm install <module_name>`
        // To download Express:
            // `npm install`

// 3. Import Express module on the doc
// Import of Express
const express = require('express');
const app = express();

// 4. Create a new route handler
const port = 3000;
app.get('/temperature/:location_code', function (request, response) { // Listen to incoming HTTP GET requests
    const varlocation = request.params.location_code;
    weather.current(location, function(error, temp_f) { // Run the weather.current function with a location parameter
        // ...
    })
})

// 5. Start an HTTP server on a given port number
let server = app.listen(port, function() { // To create a web server object that listens to incoming requests on the specific port (`port` paramenter)
    console.log(`Listening on URL http://localhost:${port}`);
})