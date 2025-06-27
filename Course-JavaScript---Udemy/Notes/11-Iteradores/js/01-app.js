//Bucle 'for' (es una función reservada) sirve para repetir un código con el intervalo que quieras usando, normalmente, una variable 'i' (item)
//Funcionamiento:   for(declaración de la función 'i' y donde empieza, hasta donde tiene que llegar el bucle (mientras 'i' no sea x, ejecuta el código), cuanto suma la variable 'i' cada vez que vuelve a empezar el código (ej: 'i++' = cada vez que termime el bucle a 'i' se le suma 1)){}

for(let i = 0; i <= 10; i++){ //Traducción de lo que dice este 'for': (se declara una variable 'let' con nomnbre 'i' (item) y le dice que el valor de 'i' empieza con el 0; mientras i sea menor o igual a 10, ejecura el siguiente código; cada vez que empieza el bucle de nuevo, se le suma 1 a 'i')
    console.log(`Numero: ${i}`);
}


//Ej: determinar que números son pares y cuales son impares:
for(let i = 1; i <= 20; i++){
    if(i % 2 === 0) {
        console.log(`El número ${i} es par`);
    } else{
        console.log(`El número ${i} es impar`)
    }
}


//Ejemplo con Arrays:
const carrito = [
    {nombre: 'Monitor 27 pulgadas', precio: 500},
    {nombre: 'Televisión', precio: 100},
    {nombre: 'Tablet', precio: 200},
    {nombre: 'Audifonos', precio: 300},
    {nombre: 'Teclado', precio: 400},
    {nombre: 'Celular', precio: 700}
]
console.log(carrito);

//Otra manera de ejecutar el contenido del 'Array'
for(let i = 0; i < carrito.length; i++) {
    console.log(carrito[i].nombre, carrito[i].precio);
}