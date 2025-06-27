'use strict';

const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
}

Object.seal(producto); //'Object.seal();' te permite modificar las llaves existentes del objeto pero no te deja ni eliminarlas ni agregar de nuevas 

// producto.disponible = false;
// producto.imagen = 'imagen.jpg';
//delete producto.precio;

console.log(producto);
console.log(Object.isFrozen(producto));