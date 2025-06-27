//Función 'for in' (para objetos):

//Diferencias entre 'for in' y 'for of' (mirar consola para ver ejemplos con más claridad):
const pendientes = ['Tarea', 'Comer', 'Proyecto', 'Estudiar JavaScript'];

for(let pendiente in pendientes) { //Si pones 'for in' en un Array te ejecutará los indices de los elementos (las posiciones), es decir, te lo ejecuta mal (no como queremos) porque 'for in' es para 'Objects'.
    console.log(pendiente);
}
for(let pendiente of pendientes) { //Si lo hacemos con un 'for of' nos ejecutará los elementos del Array (de manera correcta)
    console.log(pendiente);
}


//Ejemplo de 'for in' con Objetos:
const automovil = {
    modelo: 'Camaro',
    year: 1969,
    motor: '6.0'
}

for(propiedad in automovil) { //Crea variable automaticamente con nombre 'pendiente' para substituirlo por cada elemento del Object 'x', en este caso del Object 'automovil'
    console.log(`${automovil[propiedad]}`);
}

//Otra manera de hacer líneas 21-23 pero con 'for of' (como en este caso se tratan Objects, con el 'for in' lo puedes hacer más eficiente (más recomendable con 'for in')):
for(let [llave, valor] of Object.entries(automovil)) { //Cuando poner 'let' con '[]' puedes crear más de una variable a la vez. 'Object.entries' es una palabra reserva.
    console.log(valor);
    console.log(llave);
}