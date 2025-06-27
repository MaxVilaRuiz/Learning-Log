// Running JavaScript commands
console.log("Hello World!")

let num = 5
var mystr = "John"
console.log(num)
console.log(mystr)

const pi_val = 3.147
console.log(pi_val)

function printMyInput(user_input) {
    console.log("The parameter passed is " + user_input)
}

printMyInput(9)
printMyInput("John")

let printMyInputES6 = (user_input) => {
    console.log(user_input)
}

printMyInputES6(9)
printMyInputES6("John")

let printMyInputES6Short = user_input => console.log(user_input)

printMyInputES6Short(9)
printMyInputES6Short("John")



// Operators, Conditions, Loops
console.log("5 + 3 = ", 5 + 3)
console.log("7 - 3 = ", 7 - 3)
console.log("8 * 2 = ", 8 * 2)
console.log("27 / 3 = ", 27 / 3)
console.log("4 to the power of 3 = ", 4 ** 3)
console.log("19 mod 4 = ", 19 % 4)

console.log("5 + 3 = ", 5 + 3)
console.log("5 + \"3\" = ", 5 + "3")
console.log("5 + 5 + \"3\" = ", 5 + 5 + "3")
console.log("\"3\" + 5 + 5 = ", "3" + 5 + 5)
console.log("5 + 5 + \"3\" + 5 = ", 5 + 5 + "3" + 5)

x = 5
console.log("Old value of x: ", x)
x += 3
console.log("New value of x: ", x)

y = 5
console.log("Old value of y: ", y)
y -= 3
console.log("New value of y: ", y)

a = 6
console.log("Old value of a: ", a)
a *= 3
console.log("New value of a: ", a)

b = 6
console.log("Old value of b: ", b)
b /= 3
console.log("New value of b: ", b)

c = 6
console.log("Old value of c: ", c)
c %= 3
console.log("New value of c: ", c)

d = 6
console.log("Old value of d: ", d)
d **= 3
console.log("New value of d: ", d)

//Checking equality of 5 (number type) and 5 (string type)
console.log("5=='5' ", 5=='5')
console.log("5==='5' ", 5==='5')
console.log("5===5 ", 5===5)

console.log("5 != 5 ", 5 !== 5)
console.log("5 != 6 ", 5 != 6)
console.log("5 != '5' ", 5 !== '5')

console.log("5 > 2 ", 5 > 2)
console.log("5 > 7 ", 5 > 7)
console.log("5 > 5 ", 5 > 5)

console.log("5 < 7 ", 5 < 7)
console.log("5 < 2 ", 5 < 2)
console.log("5 < 5 ", 5 < 5)

console.log("5 >= 5 ", 5 >= 5 )
console.log("5 <= 5 ", 5 <= 5 )

var raining = false
var cloudy = true

console.log("It is raining: ", raining)
console.log("It is cloudy: ", cloudy)

console.log("It is raining AND cloudy: ", raining && cloudy)
console.log("It is raining OR cloudy: ", raining || cloudy)
console.log("It is not raining: ", !raining)
console.log("It is not cloudy: ", !cloudy)

var chocolate = true
var candy = false

console.log("There is chocolate: ", chocolate)
console.log("There is candy: ", candy)

console.log("There is candy AND chocolate: ", chocolate && candy, " -- Only candy is evaluated")
console.log("There is chocolate OR candy: ", chocolate || candy, " -- Only chocolate is evaluated")

//Accept a input from the user. If it is a number, print the multiplication table for the number. Else print the input and the length of the input.
let user_input1 = prompt('Enter a value');
//Check if the user did not input anything
if (!user_input1) {
    console.log("You did not input anything")
}
//Check if the user input is not a number
else if (isNaN(user_input1)) {
    console.log("Your input is ", user_input1)
    console.log("The length of your input is ", user_input1.length)
} 
//The only option remaining is that the input is a number
else {
    console.log(user_input1, " X 1 = ", user_input1*1)
    console.log(user_input1, " X 2 = ", user_input1*2)
    console.log(user_input1, " X 3 = ", user_input1*3)
    console.log(user_input1, " X 4 = ", user_input1*4)
    console.log(user_input1, " X 5 = ", user_input1*5)
    console.log(user_input1, " X 6 = ", user_input1*6)
    console.log(user_input1, " X 7 = ", user_input1*7)
    console.log(user_input1, " X 8 = ", user_input1*8)
    console.log(user_input1, " X 9 = ", user_input1*9)
    console.log(user_input1, " X 10 = ", user_input1*10)
}

let user_input2 = prompt('Enter a number between 1 to 7');

//Using logical OR operator to check if the input is a number and it is between 1 to 7
if(isNaN(user_input2) || user_input2< 1 || user_input2>7) {
    console.log("Invalid input")
} else {
    user_input2 = parseInt(user_input2)
    switch(user_input2){
        case 1: console.log("Sunday"); break;
        case 2: console.log("Monday"); break;
        case 3: console.log("Tuesday"); break;
        case 4: console.log("Wednesday"); break;
        case 5: console.log("Thursday"); break;
        case 6: console.log("Friday"); break;
        case 7: console.log("Saturday"); break;
        default: console.log("Invalid entry");
    }
}

//Accept a input from the user. If it is a number print the multiplication table for the number. 
let user_input3 = prompt('Enter a number');
//Check if the user input is a number
if(!isNaN(user_input3)) {
    //Using for loop for the repetitive statement
    for (let i=0; i<10; i++) {
        console.log(user_input3, " X ", i, " = ", user_input3*i)
    }
}

//The code below is to find the length of the words the user is entering. The loop will go on and on until the user chooses not to continue by pressing 'n'

let do_more = true

while(do_more) {
    //Accept a input from the user. 
    let user_input = prompt('Enter a word');
    //Check if the user input is not a number and then print the length of the input
    if(isNaN(user_input)) {
        console.log("Length of the word you entered is " + user_input.length)
    } else {
        console.log("You entered a number. Only words are allowed")
    }
    let should_continue = prompt("Do you want to continue. Press n to stop")
    
    if(should_continue === "n") {
        do_more = false
    }
}



// Collections
let myArray1 = ["Jack","Jill",4,5,true,"John"]

console.log(myArray1[0]);
console.log(myArray1[5]);

let myArray2 = ["Jack","Jill",4,5,true,"John"]

myArray2.forEach(element => {
    console.log(element)
})

let myArray3 = ["Jack","Jill",4,5,true,"John"]
for (const [index, value] of Object.entries(myArray3)) {
  console.log(index, " - ", value);
}

let myMap = new Map();

//Add a key-value pair to the map, with a key of "name" and a value of "John". 
myMap.set("name", "John")

//Add another key-value pair to the map, with a key of "age" and a value of 22.
myMap.set("age", 22)

myMap.forEach((val,key) => {
    console.log(key, " - ", val)
})