// Adding nodes to the HTML document:
function addPara() {
    // Definition:
    var newPara = document.createElement("p"); // To specify the type of the element
    var newText = document.createTextNode("Hello World"); // To create a text in the document;

    // Implementation:
    newPara.appendChild(newText); // Create a child of an element with a value
    document.body.appendChild(newPara);
}



// Window object methods and events:
// Add 'window.' before the method if someone doesn't work correctly
open("url", "name", [features, replaces]); // "features" represents the dimension of the new window. "replaces" is a boolean that tels whether the opened website will or not replace the actual website.

onload = (function() {
    // To start a function after the page is loaded
    // Statements
});

dump("message") // Writes a string into the console of the browser

scrollTo("x-value", "y-value") // Scroll the web browser to a particular set of coordinates

alert('Alert text'); // Show the introduced text as a alert message in the window

confirm('Confirm message');

prompt('message', 'defaultReply'); // To show a message in the screen to introduce an input



// REST Architecture:
// POST -> Create
// GET -> Read
// PUT -> Update
// DELETE -> Delete