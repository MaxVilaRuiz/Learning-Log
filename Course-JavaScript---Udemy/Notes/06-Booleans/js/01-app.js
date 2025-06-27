const boolean1 = true;
const boolean2 = false;
const boolean3 = 'true';

console.log(boolean1);
console.log(boolean2);
console.log(typeof boolean1);

console.log(boolean1 == boolean3); //Resultado = false (aunque sea comparador no estricto)

const boolean4 = new Boolean(true); //Otra manera de crear un valor booleano PERO es un objeto con clase Boolean porque usa 'new' y 'Boolean(x)'.
console.log(typeof boolean4);