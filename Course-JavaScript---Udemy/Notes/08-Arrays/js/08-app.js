const producto = {
    nombre: 'Monitor 20 Pulgadas',
    precio: 300,
    disponible: true
}

//Destructuring con Objects (07-Objetos/04-app.js)
// const nombre = producto.nombre; //Para extraer variables de objetos y independizarlo
// console.log(nombre);

//Destructuring / extraer valores de objetos i les crea una variable propia
const { nombre } = producto;
console.log(nombre);



//Destructuring con Arrays: para probar ejemplos es necessario comentar algunas lineas para solucionar problemas
const numeros = [10, 20, 30, 40, 50];

const [primero, segundo, tercero] = numeros; //Crea 3 variables del Array 'numeros' con los nombres 'primero, segundo y tercero' a partir de las posiciones (1, 2 y 3) --> reconoce automaticamente la posición del Array 'x' dependiendo de la posición de ',' que le asignes entre los '[]': const [posición 1, posición 2, posición 3, posición 4...] = array; <-- de este array (y crea las 4 variables son los nombres que quieras segun las posiciones correspondientes)

const [, , , , quinto] = numeros; //Si solo quieres crear una variable del valor de la posición 'x' de un Array pones , de las posiciones que no te interesen (en este caso solo queremos la quinta posición y se crea la variable con el nombre 'quinto')

const [primero, ...tercero] = numeros; //Falta información

console.log(tercero);