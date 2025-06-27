const autenticado = true;

if(autenticado === true){
    console.log('El ususario esta autenticado');
}
if(autenticado){ //Otra manera de hacer líneas 3, 4 y 5 (manera de líneas 6, 7 y 8 es más recomendable y profesional)
    console.log('El ususario esta autenticado');
}


//Ejemplo juego:
const puntaje = 500;
if(puntaje > 400){
    console.log('Excelente!!!');
} else if(puntaje > 300){
    console.log('Buen puntaje... felicidades');
}

//Misma manera de hacer líneas 12-17 pero ponerlo todo en una función y con los 'return' en los 'if' es más profesional
function valoracionPuntaje(){
    if(puntaje > 400) {
        console.log('Excelente!!!');
        return;
    }
    if(puntaje > 300){
        console.log('Buen puntaje... felicidades');
        return;
    }
}
valoracionPuntaje();