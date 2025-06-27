const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 'Julio'];

const carrito = [
    { nombre: 'Monitor 27 Pulgadas', precio: 500 },
    { nombre: 'Televisión', precio: 100 },
    { nombre: 'Tablet', precio: 200 },
    { nombre: 'Audifonos', precio: 300 },
    { nombre: 'Teclado', precio: 400 },
    { nombre: 'Celular', precio: 700 },
];

meses.forEach((mes, i) => { //El segundo valor (En esete caso = 'i') en el Method 'forEach()' te returna las posicions de los elementos en orden, el primer valor del Method te returna el valor de la cada variable. Comprobar para ver más claramente.
    console.log(i);
})

//Encontrar el índice de Abril sin Methods en Arrays tradicionales:
meses.forEach((mes, i) => {
    if(mes === 'Abril') {
        console.log(`Encontrado en el índice ${i}`);
    }
})

//Encontrar el índice de Abril con Methods en Arrays tradicionales:
const indice = meses.findIndex(mes => mes === 'Diciembre'); //Otra manera de hacer líneas 16-20. Con Mehods es mejor.
console.log(indice);


//Encontrar un índice de un Array de objetos:
const indice2 = carrito.findIndex(producto => precio.producto === 100);
console.log(indice2);