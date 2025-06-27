const producto = {
    nombre: 'Monitor de 20 Pulgadas',
    precio: 300,
    disponible: true
}

//Object Constructor --> otra manera de crear objetos
function Producto(nombre, precio) { //lo que va entre '()' en una función se llama 'concepto/s'
    this.nombre = nombre;
    this.precio = precio;
    this.disponible = true;
}

const producto2 = new Producto('Monitor 24 pulgadas', 500); //Para no crear constantemente objetos con la misma estructura, se crea una función / clase y se la llama, como en las líneas 14 y 17, y se le añaden los parametros que queremos entre los "()" --> solo sirve cuando quieres la misma estructura del objeto para distintas ocasiones, si quieres estructuras distintas debes hacerlo de otro método
console.log(producto2);

const producto3 = new Producto('Television', 100);
console.log(producto3);