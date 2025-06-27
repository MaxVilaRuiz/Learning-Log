const numeros = [10, 20, 30, 40, 50, [1,2,3]];
console.log(numeros);
console.table(numeros); //Sirve para poder ver en la consola la variable en forma de tabla (para ver el índice (posiciones que exsiten en el Array) y el valor correspondiente)

//Para acceder a un valor específico del Array
console.log(numeros[2]); //Posición 2 del Array
console.log(numeros[20]); //Aquí saldría error porque no existe ningún valor en la posición '20' de Array
console.log(numeros[5][1]) //Entramos en el Arrray de la posición '5' y después elegimos la posición del valor que queremos ver del Array