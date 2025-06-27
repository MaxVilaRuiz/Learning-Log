//Maneras de juntos / concatenar Strings
const producto = 'Monitor 20 Pulgadas';
const precio = '30 USD';
console.log(producto.concat(precio));
console.log(producto.concat('En descuento'));
console.log(producto + precio);
console.log('El producto' + producto + 'tiene un precio de' + precio);
console.log('El producto', producto, 'tiene un precio de', precio);
console.log('El Producto ${producto} tiene un precio de $(precio)') //Como fString de Python pero para introducir variables hay que poner $(var) en JS