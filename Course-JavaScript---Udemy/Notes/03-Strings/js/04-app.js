const producto = '     Monitor 20 pulgadas     ';
console.log(producto);
console.log(producto.length); //Los espacios en blanco también cuentan
console.log(producto.trimStart()); //Para eliminar los espacios en blanco antes de empezar el String
console.log(producto.trimEnd()); //Para eliminar los espacios en blanco al final del String
console.log(producto.trimStart().trimEnd()); //Para mezclar methods
console.log(producto.trim()); //Para eliminar todos los espacios en blanco