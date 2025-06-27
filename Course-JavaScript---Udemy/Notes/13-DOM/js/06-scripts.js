const encabezado = document.querySelector('.contenido-hero h1');
console.log(encabezado);

//Para acceder a un texto determinado desde el código JavaScript:
//Primero se guarda un el contenido de un selector en una variable (como se ha hecho arriba) y después de aplican los siguientes métodos.
console.log(encabezado.innerText); //Te muestra todo el contenido de la etiqueta incluyendo las mismas etiquetas (como '.innerHTML') pero si le añades un estilo de 'visibility-hidden', puede ocultarlo (mediante estilos CSS).
console.log(encabezado.textContent); //Te muestra el contenido de la etiquetada deseada (pero sin las etiquetas. Ex: '<h1></h1>').
console.log(encabezado.innerHTML); //Te muestra todo el contenido de la etiqueta incluyendo las etiquetas.

//Modificar texto:
const nuevoHeading = 'Nuevo Heading';
document.querySelector('.contenido-hero h1.').textContent = nuevoHeading;

//Modificar imagen:
const imagen = document.querySelector('.card img');
imagen.src = 'img/hacer2.jpg'; //Cambiamos la imagen que esta asignada en la variables 'imagen' por otra llamada 'img/hacer2.jpg'.