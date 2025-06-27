//Que se puede hacer con la clase Math.x?
let resultado;

//PI
resultado = Math.PI;

//Redondear
resultado = Math.round(2.8); 
resultado = Math.round(2.3); 

//Redondear hacia arriba
resultado = Math.ceil(2.3);

//Redondear hacia abajo
resultado = Math.floor(2.8); 

//Raiz cuadrada
resultado = Math.sqrt(144);

//Valor absoluto
resultado = Math.abs(-500);
resultado = Math.abs(500);

//Potencia
resultado = Math.pow(2, 4); //(base, potencia)

//Para que te encuentre el valor mínimo
resultado = Math.min(3, 5, 1, 12, -3);

//Para que te encuentre el valor máximo
resultado = Math.min(3, 5, 1, 12, -3);

//Aleatorio (falta explicación --> es un poco raro (.random()))
resultado = Math.random() * 20; 

// //Aleatorio dentro de un rango
resultado = Math.floor(Math.random() * 30); //Rango del 0 al 30

console.log(resultado);