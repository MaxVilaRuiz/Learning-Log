//Forma imperativa: (otra manera de hacer 05-app.js y 06-app.js)

const carrito = [];
const producto = {
    nombre: 'Monitor 32 Pulgadas',
    precio: 400
}
const producto2 = {
    nombre: 'Celular',
    precio: 800
}
const producto3 = {
    nombre: 'Teclado',
    precio: 50
}
const producto4 = {
    nombre: 'Celular 2',
    precio: 100
}

carrito.push(producto2, producto, producto4);
carrito.unshift(producto3);

console.table(carrito);

//Eliminar último elemento de un Array:
carrito.pop();

console.table(carrito);

//Eliminar un elemento del principio del Array:
carrito.shift();

console.table(carrito);

//Eliminar elementos específicos: array.splice(posición del array a la cual empiezas, cantidad de elementos que va a eliminar a partir de esa posición)
carrito.splice(1, 1); //Posición 3 de Array y cantidad 1
console.table(carrito);