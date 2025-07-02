// Callback function
weather.current(location, function(error, temp_f) { // Assign an error parameter to check if an error has occurred
    if (error) {
        console.error(error);
        return;
    }
    console.log(temp_f);
});
response.end(`... ${temp_f} ...`);


// Passing an error object
exports.current = function(location, resultCallback) {
    // ...
    http.request(options, function(response) {
        let buffer = '';
        let result = '';

        response.on('data', function(chunk) {
            buffer += chunk;
        });

        response.on('end', function() {
            parseString(buffer, function(error, result) {
                if (error) {
                    resultCallback(error);
                    return;
                }
                resultCallback(null, result.current_observation.temp_f[0]);
            });
        });
    });
}