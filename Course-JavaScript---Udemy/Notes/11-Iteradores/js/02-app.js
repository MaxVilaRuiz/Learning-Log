//Diferencias entre 'break' y 'continue':

//Ejemplo 'break':
for(let i = 0; i <= 10; i++){
    if(i === 5){
        console.log('Este es el 5');
        break; //Si pones break, se va dejar de ejecutar el código restante haciendo que solo ejecute las líneas anteriores  y se va a salir del 'loop', en este caso el 'for' (mirar console.log para ver ejemplo)
    }
    console.log(`Numero: ${i}`);
}

//Ejemplo 'continue':
//Ej1:
for(let i = 0; i <= 10; i++){
    if(i === 5){
        console.log('Este es el 5');
        continue; //Si pones break, se va dejar de ejecutar el código restante haciendo que solo ejecute las líneas anteriores  pero no se va a salir del 'loop', en este caso el 'for', así que va a seguir ejecutando el 'loop' aunque con el siguiente valor (mirar console.log para ver ejemplo)
    }
    console.log(`Numero: ${i}`);
}
//Ej2:
const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200, descuento: true},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]
for(let i = 0; i < carrito.length; i++) {
    if(carrito[i].descuento) {
        console.log(`El artículo ${carrito[i].nombre} tiene descuento`);
        continue;
    }
    console.log(carrito[i].nombre);
}