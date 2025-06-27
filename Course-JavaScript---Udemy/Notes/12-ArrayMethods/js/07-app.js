const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 'Julio'];
const meses2 = ['Agosto', 'Septiembre'];
const meses3 = ['Octubre', 'Noviembre', 'Diciembre'];

const resultado = meses.concat(meses3); //Sirve para concatenar un Array a una variable, es decir, para copiar el contenido de un Array a una variable. IMPORTANTE: junta el valor de 'X1.concat(X1)' las dos 'X' en una variable a parte, la 'X' es el valor que siempre mantiene y la 'X1' o incluso si hay más entre los parentesis del '.concat()' són las que se añaden al valor de 'X' en la variable a parte.
console.log(resultado);

//Spread operator, sirve para hacer de otra manera líneas 6 y 7:
const resultado2 = [...meses, ...meses2];
console.log(resultado2);