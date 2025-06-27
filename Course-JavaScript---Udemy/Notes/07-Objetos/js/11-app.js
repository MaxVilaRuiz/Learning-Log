// const nombre = 'Hola';
// const precio = 20;
const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true,
    mostrarInfo: function() { //Para definir función dentro de objeto
        console.log(`El producto: ${this.nombre} tiene un precio de: ${this.precio}`) //Para hacer f-String debes poner texto entre `` y llamar variables con "${x}". Para que el objeto mire las variables de el mismo debes poner "this.variable", sinó te leera las variables externas (línea 1 y 2)
    }
}
const producto2 = {
    nombre: 'Tablet',
    precio: 3000,
    disponible: true,
    mostrarInfo: function() {
        console.log(`El producto: ${this.nombre} tiene un precio de: ${this.precio}`)
    }
}

producto.mostrarInfo(); //Estamos llamando la función del objeto y se muestra por la consola porque asi lo dice en el contenido de la función
producto2.mostrarInfo(); 