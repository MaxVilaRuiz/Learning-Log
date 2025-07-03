// Parse JSON data from HTTP message

// Parse (a JSON string to a JS objects) with JSON.parse():
let json = '{"result": true, "count": 42}';
obj = JSON.parse(json);
console.log(obj.count); // 42
console.log(obj.result); // true


// Stringify (converts a JS object to a JSON string) with JSON.stringify():
console.log(JSON.stringify({x:5, y:6})); // '{"x":5, "y": 6}'