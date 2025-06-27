//Diferencia entre Methods 'forEach()' y 'reduce()':

const carrito = [
    { nombre: 'Monitor 27 Pulgadas', precio: 500 },
    { nombre: 'Televisión', precio: 100 },
    { nombre: 'Tablet', precio: 200 },
    { nombre: 'Audifonos', precio: 300 },
    { nombre: 'Teclado', precio: 400 },
    { nombre: 'Celular', precio: 700 },
];

//Ejemplo con un 'forEach()':
let total = 0;
carrito.forEach(prodcuto => total += prodcuto.precio);
console.log(total);

//Ejemplo con un 'reduce()':
let resultado = carrito.reduce((total, producto) => total + producto.precio, 0); //Otra manera de hacer líneas 13-15. Te crea automaticamente dos variables con los nombres que uno quiera y depende del orden de la variable harà un función ya programada o no (primera función = total, segunda posición = elementos del Array). Al final pone un ',0' porque define el valor al qual quiere empezar. 
console.log(resultado);