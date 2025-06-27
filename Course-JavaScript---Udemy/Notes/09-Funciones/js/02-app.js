//Diferencia entre las maneras de declarar una función:
//Info necessaria antes de saber las diferencias: JavaScript le da las llamadas '2 vueltas' al programa. La primera vuelta sirve para reconocer y recordar las funciones... Y la segunda para ejecutar las variables o funciones (cuando sean llamadas)

sumar();
function sumar() { //Esta es directamente una función y lo lee en la primera vuelta
    console.log(2+2);
}

sumar2();
const sumar2 = function() { //Esta linea define una función dentro de una variable y como no es función desde el inicio lo ejecuta en la segunda vuelta
    console.log(3+3);
}