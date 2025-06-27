const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]

for(let i = 0; i < carrito.length; i++ ) { //
    console.log(`${carrito[i].nombre} - Precio: ${carrito[i].precio}`); //f-String
}

//Otra manera de hacer linea 10 y 11:
carrito.forEach(function (producto){ //var.forEach() <-- es un method que si defines una función anonima y pones el nombre de la variable del argumento (como se fuera el 'item' del for()) te hace automaticamente la estructura del for de las lineas 10 y 11 (más automatizado)
    console.log(`${producto.nombre} - Precio: ${producto.precio}`);
})