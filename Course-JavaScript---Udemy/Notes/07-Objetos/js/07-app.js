const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
}

producto.disponible = false; //Se puede reasignar el valor de una variable dentro de un objeto aunque el objeto este definido por 'cons'
delete producto.precio; //También se pueden eliminar
console.log(producto);
