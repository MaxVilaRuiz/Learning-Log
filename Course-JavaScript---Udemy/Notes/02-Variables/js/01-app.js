//JavaScript és dinamico, no hace falta especificar el tipo de variable que es (int, float, str...)
var producto = "Monitor de 24 pulgadas"; //"var" para crear variable general (para todos los archivos enlazados)
console.log(producto); //"console.log" sirve para imprimir el valor de la variable en la terminal
producto = "Monitor de 19 pulgadas"; //para reasignar valor de variable
console.log(producto);
producto = 20;
console.log(producto);
//Las variables también se pueden inicializar sin valor y asignarlo después
var disponible;
disponible = true;
disponible = false;

//Para inicializar múltiples variables puedes poner una única vez "var" y poner "," entre variables (en la misma linea o tabulando en otras lineas) + ";" al final del codigo.
var categoria = 'Computadoras',
    marca = 'Marca Famosa',
    calificacion = 5;

//Las variables no se pueden iniciar con números
//var 09_4;
var _09_4;

//Se recomienda más la primera (camel case), segunda = snake
var nombreProducto;
var nombre_producto;