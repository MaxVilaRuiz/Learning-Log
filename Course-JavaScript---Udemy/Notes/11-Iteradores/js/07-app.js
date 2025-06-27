//Función 'for of' (para Arrays):

const pendientes = ['Tarea', 'Comer', 'Proyecto', 'Estudiar JavaScript'];
const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200, descuento: true},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]

for(let pendiente of pendientes) { //Crea variable 'let' con nombre 'pendiente' para substituirlo por cada elemento del Array 'x', en este caso del Array 'pendientes'
    console.log(pendiente);
}

for(let producto of carrito) { //Igual que líneas 13-15 pero con otro Array
    console.log(producto.nombre);
}