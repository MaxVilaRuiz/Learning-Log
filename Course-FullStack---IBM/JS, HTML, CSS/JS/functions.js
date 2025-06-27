// AJAX:
// Asynchronous JavaScript and XML. Functions that wait for the response of the backend.



// Prototypes / Structs / Classes: 
function Car(make, model, year) {
    // 'this' refer to the object that is refered to the function.
    this.make = make;
    this.model = model;
    this.year = year;

    // To create a method for the struct:
    this.getName = function () {
        return this.make + ' ' + this.model + ' ' + this.year;
    }
}

// Another way to create the method for the prototype 'Car':
Car.prototype.getName = function() {
    return this.make + ' ' + this.model + ' ' + this.year;
}



// Self-executing functions:
// Are executed when the program starts running
(function () {
    //statements
})