//En este apartado (12-ArraysMethods) se ven las diferencias de usar ciertos ArrayMethods para Arrays tradicionales y para Arrays de objectos.

const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 'Julio'];

const carrito = [
    { nombre: 'Monitor 27 Pulgadas', precio: 500 },
    { nombre: 'Televisión', precio: 100 },
    { nombre: 'Tablet', precio: 200 },
    { nombre: 'Audifonos', precio: 300 },
    { nombre: 'Teclado', precio: 400 },
    { nombre: 'Celular', precio: 700 },
];

//Comprobar si un valor existe en un Array:
meses.forEach(mes => {
    if(mes == 'Enero') {
        console.log('Enero si exista');
    }
})

const resultado = meses.includes('Enero'); //Te  dice si ('x') existe o no. Da un resultado Boolean. Otra manera de hacer líneas 15-19
console.log(resultado);

//En un Array de objetos se utiliza '.some' para saber si un valor existe dentro de el:
const exsite = carrito.some(producto => producto.nombre === 'Celular');
console.log(existe);

//En un Array tradicional con '.some' (se usa de igual manera y tiene el mismo resultado que con Arrays de objetos):
const existe2 = meses.some(mes => mes === 'Febrero');
console.log(existe2);