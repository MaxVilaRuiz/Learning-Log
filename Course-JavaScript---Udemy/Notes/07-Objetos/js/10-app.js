const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
}

const medidas = {
    peso: '1kg',
    medida: '1m'
}

console.log(producto);
console.log(medidas);

const resultado = Object.assign(producto, medidas); //Repaso: 'Object' es una clase porque tiene la primera en mayúscula y 'assign()' es un método o función porque lleva '()'

//Spread Operator o Rest Operator --> name
const resultado2 = {...producto, ...medidas}; //Los '...' sirven para tomar una copia del objeto y lo pone dentro de un nuevo objeto (misma manera de hacer línea 15 pero línea 18 es más recomendable)
console.log(resultado);