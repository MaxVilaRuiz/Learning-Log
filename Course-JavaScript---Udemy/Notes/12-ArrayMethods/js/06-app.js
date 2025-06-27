//Methods '.every()', sirve para retornar en forma Booleana si una variable cumple o no una cierta condición:

const carrito = [
    { nombre: 'Monitor 27 Pulgadas', precio: 500 },
    { nombre: 'Televisión', precio: 100 },
    { nombre: 'Tablet', precio: 200 },
    { nombre: 'Audifonos', precio: 300 },
    { nombre: 'Teclado', precio: 400 },
    { nombre: 'Celular', precio: 700 },
];

//Ejemplo con '.every()':
const resultado = carrito.every(producto => producto.precio < 500);
console.log(resultado);

//Ejemplo con '.some()':
const resultado2 = carrito.some(producto => producto.precio < 500);
console.log(resultado2);