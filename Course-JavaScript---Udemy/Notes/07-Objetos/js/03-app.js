const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
    //imagen: 'imagen.jpg'
}

//Agregar nuevas propiedades al objeto
producto.imagen = 'imagen.jpg'; //Otra manera de hacer línea 5

//Eliminar propiedades del objeto
delete producto.disponible;

console.log(producto);