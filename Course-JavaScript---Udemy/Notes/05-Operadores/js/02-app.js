const numero1 = 20;
const numero2 = '20';
const numero3 = 30;

// Revisar si 2 números son iguales (comparador no muy estricto --> le da igual si es int o str, si es igual es igual)
console.log(numero1 == numero3);
console.log(numero1 == numero2);

//Comparador estricto (mira si es igual en todos los sentidos: valor, tipo de dato...)
console.log(numero1 === numero2);
console.log(numero1 === parseInt(numero2)); //Ahora dará true porque estamos pasando el String a Int con la función 'parseInt()'
console.log(typeof numero1); //"typeof" te imprime el tipo de dato de la variate (string, int, float, bool...)
console.log(typeof numero2);

//Ver si son diferentes. '!=' no es estricto, '!==' sí es estricto
const password1 = 'admin';
const password2 = 'Admin';
console.log(password1 != password2);
console.log(numero1 != numero2); //Resultado = false porque no es un diferenciador estricto
console.log(numero1 !== numero2); //Resultado = true porque es un diferenciador estricto