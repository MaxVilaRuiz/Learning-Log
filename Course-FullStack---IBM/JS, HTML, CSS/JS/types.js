typeof "variable" // To know the type (ex: string)


// Arrays:
numArray = new Array(0, 1, 2, 3); // Way to create an array
numArray2 = [0, 1, 2, 3] // Another way to create an array


// Data Objects:
// def: are a snapshot of an exact millisecond in time
var today = new Date(); // Returns the local data and time
var newDate = new Date("2012-1-17 13:15:30"); // Created from a string
var newDate2 = new Date(2012, 0, 17); // Created from a number


//Error Types:
// TypeError, RangeError, URIError, EvalError, ReferenceError
throw new Error("Say why is an error"); // Create an error
function error(item) {
    alert('There is a problem in this item.')
    item.focus(); // To focus the error.
}