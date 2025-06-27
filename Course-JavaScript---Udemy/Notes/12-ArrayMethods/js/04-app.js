//Method '.filter()' sirve para filtrar valores específicos de variables en Arrays de todos los tipos.

const carrito = [
    { nombre: 'Monitor 27 Pulgadas', precio: 500 },
    { nombre: 'Televisión', precio: 100 },
    { nombre: 'Tablet', precio: 200 },
    { nombre: 'Audifonos', precio: 300 },
    { nombre: 'Teclado', precio: 400 },
    { nombre: 'Celular', precio: 700 },
];

let resultado;
resultado = carrito.filter(producto => producto.precio > 400); //Ejemplo: quiero que me returne todos los valores superiores a 400 de las variables del Array. Mirar 'console.log()' para entender mejor.
resultado = carrito.filter(producto => producto.precio !== 'Audifonos'); //Ejemplo: quiero que me retorne todos los valores de las variables del Array que su valor no sea igual a 'Audifonos'.
console.log(resultado);