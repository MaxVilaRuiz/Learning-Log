const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]

newArray.forEach(function (producto) { //Salta error porque no hay ninguna variable que se llame 'newArray' porque el 'var.forEach(function(item)){}' no crea variables
    return `${producto.nombre} - Precio: ${producto.precio}`;
})

//Otra manera de hacer linea 10 y 11:  crea arreglo nuevo
newArray2 = carrito.map(function (producto) { //var.map(function(item)){} <-- crea arrreglo nuevo a diferencia del '.forEach()'
    return `${producto.nombre} - Precio: ${producto.precio}`;
})
console.log(newArray2);