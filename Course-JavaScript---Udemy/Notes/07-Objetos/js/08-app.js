'use strict'; //Para que evalue el codigo de JavaScript en modo estricto (como el === en Boolean) --> te va a restringir cierto codigo

const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
}

Object.freeze(producto); //Congela 'x' para que no se pueda reasignar posteriormente

//Siguientes lineas dan error si el objeto esta congelado
// producto.disponible = false;
// producto.imagen = 'imagen.jpg';

console.log(producto);
console.log(Object.isFrozen(producto)); //Para que te diga si 'x' esta congelado o no (true or false);