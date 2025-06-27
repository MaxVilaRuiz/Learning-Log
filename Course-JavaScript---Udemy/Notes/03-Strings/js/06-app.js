//.repeat() te permite repetir "x" veces una cadena
const producto = 'Monitor 20 Pulgadas';
const texto = 'en Promición'.repeat(3);
console.log(texto);
console.log(`${producto} ${texto} !!!`)
console.log(producto.repeat(3));

//.split(x) divide el Sting por cada caracter "x" que se encuentre
const actividad = 'Estoy aprendiendo JavaScript moderno';
console.log(actividad.split(' '));
const hobbies = 'Leer, caminar, escuchar música, escribir, aprender a programar';
console.log(hobbies.split(', '));
const tweet = 'Aprendiendo JavaScript #JSModernoCurso';
console.log(tweet.split('#'));