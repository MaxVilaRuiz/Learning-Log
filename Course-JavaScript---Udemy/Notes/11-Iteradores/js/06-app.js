//Bucle 'forEach' --> es una 'Arrow Function' (ideal para Arrays):

const pendientes = ['Tarea', 'Comer', 'Proyecto', 'Estudiar JavaScript'];

pendientes.forEach( (pendiente, indice) => { //Mira cada elemento del Array (traducción = por cada...)
    console.log(`${indice} : ${pendiente}`); //Con el 'indice' miras la posición del elemento en el Array
})

//Otro ejemplo:
const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200, descuento: true},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]

// carrito.forEach( producto => console.log(producto.precio)); Puede hacer el 'forEach()' así y no te crea necesariamente una variable nueva

const nuevoArreglo = carrito.map( producto => console.log(producto.precio)); //'map' te crea un nuevo Array automaticamente cuando ejecuta su contenido, a diferencia de 'forEach'
const nuevoArreglo2 = carrito.forEach( producto => console.log(producto.precio)); //Para ver diferencia entre 'forEach()' y 'map()' en la consola

console.log(nuevoArreglo);
console.log(nuevoArreglo2);