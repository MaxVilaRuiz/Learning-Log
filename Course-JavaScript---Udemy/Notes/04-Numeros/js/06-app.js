const numero1 = '20';
const numero2 = '20.2';
const numero3 = 'Uno';
const numero4 = 20;

console.log(numero1);
console.log(Number.parseInt(numero1)); //Convertir a Int = Number.parseInt(x)
console.log(Number.parseFloat(numero1)); //Convertir a Float = Number.parseFloat(x)
console.log(Number.parseFloat(numero3)); //Da error (Not a Number)

//Para revisar si es entero o no (true or false)
console.log(Number.isInteger(numero4));
console.log(Number.isInteger(numero3));