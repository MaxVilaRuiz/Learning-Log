const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
}
// const nombre = producto.nombre; //Para extraer variables de objetos y independizarlo
// console.log(nombre);

//Destructuring / extraer valores de objetos i les crea una variable propia
const { nombre } = producto; //Otra manera de hacer línea 6
const { precio } = producto;
console.log(nombre);
console.log(precio);

//Líneas 10 y 11 más simplificadas:
// const { nombre, precio } = producto;