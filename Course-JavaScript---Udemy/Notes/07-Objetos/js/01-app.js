//A un objecto le puedes añadir methods pero a una variable no pueddes a no ser que sea String
const nombre = 'Monitor de 20 Pulgadas';
const precio = 300;
const disponible = true;

//Un objeto agrupa todo en una sola variable
const producto = {
    nombre: 'Monitor de 20 Pulgadas', //Cuando se define una variable dentro de un objeto se usa ':' después del nombre de la variable en lugar de '='
    precio: 300, //Si quieres poner más de una variable dentro de un objeto debes poner ',' al final de la línea en lugar de ';'
    disponible: true
}

console.log(producto);