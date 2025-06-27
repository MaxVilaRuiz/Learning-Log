const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true,
    informacion: { //Crear objetos dentro de objetos
        medidas: {
            peso: '1kg',
            medida: '1m'
        },
        fabricacion: {
            pais: 'China'
        }
    }
}

const { nombre, informacion, informacion: {fabricacion, fabricacion: {pais}}} = producto; //Puedes extraer un objeto de un objeto i ponerlo dentro de una nueva variable
console.log(nombre);
console.log(informacion);
console.log(fabricacion);
console.log(pais);