const encabezado = document.querySelector('h1');
console.log(encabezado.style); //Te muestra todos los estilos de la etiqueta de la variable.

encabezado.style.backgroundColor = 'red'; //'.backgroundColor' para modificar el fondo de la etiqueta seleccionada en la variable en cuestión.
encabezado.style.fontFamily = 'Arial'; //'.fontFamily' para modificar la fuente de la etiqueta en cuestión.
encabezado.style.textTransform = 'uppercase'; //'.uppercase' para modificar la etiqueta en cuestión.
//Palabras como las mostradas anteriormente, com: 'uppercase', 'Arial' o 'red'. Aunque parezca que son valores String, son palabras reservada y, es por eso, que permiten efectuar cambios en los elementos.

const card = document.querySelector('.card');
card.classList.add('nueva-clase', 'segunda-clase'); //Para añadir una clase a una etiqueta (poner ',' para añadir más de una).
card.classList.remove('card'); //Para eliminar una clase 'x'. En este caso elimina la clase '.card' pero permanecen los otros ya que ha selecciona un elemento y las clases creadas anteriormente no se crean dentro de clase.
console.log(card.classList);