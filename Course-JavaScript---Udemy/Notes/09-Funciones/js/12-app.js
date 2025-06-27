const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]

newArray = carrito.map( producto => `${producto.nombre} - Precio: ${producto.precio}`); //Recordatorio: 'var.map()' puede crear variables, 'var.forEach()' no
console.log(newArray);

carrito.forEach( producto => console.log(`${producto.nombre} - Precio: ${producto.precio}`)); //Otra manera de hacer línea 10 y 11