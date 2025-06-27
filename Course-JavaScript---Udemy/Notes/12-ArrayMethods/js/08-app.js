const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 'Julio'];

const carrito = [
    { nombre: 'Monitor 27 Pulgadas', precio: 500 },
    { nombre: 'Televisión', precio: 100 },
    { nombre: 'Tablet', precio: 200 },
    { nombre: 'Audifonos', precio: 300 },
    { nombre: 'Teclado', precio: 400 },
    { nombre: 'Celular', precio: 700 },
];

//Spread operator con Array de índices:
const meses2 = ['Agosto', ...meses]; //Crea variable 'meses2' y le agrega los valores entre los '[]' en su orden correspondiente.
console.log(meses2);

const producto = {producto: 'Disco Duro', precio: 300}; //También se pueden agregar objetos en otras variables con el Spread operator.
const carrito2 = [...carrito, producto];
console.log(carrito2);