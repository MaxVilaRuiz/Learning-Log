//Declaración de función (Function Declaration)
function sumar() { //Todo lo que haya dentro de las '{}' sera lo que haga 'sumar()', en este caso, cuando sea declarada
    console.log(2+2);
}
sumar(); //Así se declara una función
sumar();
sumar(); //Puedes declarar la función más de una vez

//Expresión de función (Function Expression) <-- Otra manera de declarar una función (más actual)
const sumar2 = function() { //Crea variable y dice que es una función anonima (porque no tiene nada entre los parentesis)
    console.log(3+3);
}
sumar2();