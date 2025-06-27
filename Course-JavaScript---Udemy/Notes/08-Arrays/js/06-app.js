//Forma declarativa: (otra manera de hacer 05-app.js)

const carrito = [];
const producto = {
    nombre: 'Monitor 32 Pulgadas',
    precio: 400
}
const producto2 = {
    nombre: 'Celular',
    precio: 800
}
const producto3 = {
    nombre: 'Teclado',
    precio: 50
}

let resultado;
resultado = [...carrito, producto]; //Recordatorio: '...variable' para copiar el valor y contenido de la variable a la nueva
resultado = [...resultado, producto2];
resultado = [producto3, ...resultado];
console.table(resultado);