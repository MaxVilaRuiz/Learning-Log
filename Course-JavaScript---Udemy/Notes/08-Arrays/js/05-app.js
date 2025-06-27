const meses = ['Enero', 'Febrero', 'Marzo'];
//meses[3] = 'Abril';

//Agregar al final del Array
meses.push('Abril') //Misma manera de hacer línea 2 pero más automatizada (respecto a la posición) y más recomendable

console.table(meses);



//Ejemplo carrito de compra:
const carrito = [];

//Definir producto
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

carrito.push(producto, producto2); //'array.push' para agregar al final del Array
carrito.unshift(producto3); //'array.unshift' para agregar al principio del Array 

console.table(carrito);