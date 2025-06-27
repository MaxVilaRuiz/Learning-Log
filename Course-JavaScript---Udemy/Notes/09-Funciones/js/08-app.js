function sumar(a, b) {
    return a+b; //Para ejecutar lineas de función es más professional y recomendado usar 'return'
}
console.log(sumar(2, 3));

const resultado = sumar(2, 3); //Otra manera de hacer línea 4 (más recomendable hacer linea 6 y 7)
console.log(resultado);


//Ejemplo avanzado
let total = 0;
function agregarCarrito(precio){
    return total += precio;
}
function calcularImpuesto(total){
    return total * 1.21;
}
total = agregarCarrito(300);
total = agregarCarrito(100);
total = agregarCarrito(600);

const totalPagar = calcularImpuesto(total);
console.log(total);
console.log(`El total a pagar es de ${totalPagar}`);