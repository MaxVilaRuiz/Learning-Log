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



// Best Practices

// Folder Structure
//  Project:
//      node_modules: modules & packages
//      config: configuration files such as DB connections, environment variables, credentials files (API keys for external services...)...
//      models: data models, which specify the type if data store defined by an ORM library
//      routes: specify routes for all entries, one file of each logical set of routes
//      views: contain templates dynamically write HTML, CSS, JS for the client
//      public: contain static content such as images, CSS & JS (helpful to have sub-folder for each type of content)
//      app.js: main configuration of the project
//      routes.js: central location to access routes (imports all files from routes folder & exports them as a single module to app.js)
//      package.json

// Folder Structure for API
//  Project:
//      node_modules: modules & packages
//      config: configuration files such as DB connections, environment variables, credentials files (API keys for external services...)...
//      models: data models, which specify the type if data store defined by an ORM library
//      routes: specify routes for all entries, one file of each logical set of routes
//      app.js: main configuration of the project
//      routes.js: central location to access routes (imports all files from routes folder & exports them as a single module to app.js)
//      package.json

// Testing REST APIs
// For black-box test use SuperTest (module included in the Mocha framework)

// API documentation
// Documentation open-source projects: API Blueprint, Swagger

// Using Node Package Manager (npm)
// `npm init` when initializing
// `--save` or `--save-dev` to make suree correct dependencies are installed when moving to a different platform
// `npm ...` to install module

// Conventions
// files: all with lowercase
// variables: camel case
// npm modules: lowercase separated with '-'
// requiring npm modules: camel case (ex: require('myModule'))