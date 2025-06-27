const primerEnlace = document.querySelector('a');
primerEnlace.remove(); //Para eliminar un elemento.
console.log(primerEnlace);

//Para eliminar desde el padre:
const navegacion = document.querySelector('.navegacion');
console.log(navegacion.children); //Recordatorio: '.children' sirve para acceder a los elementos reales 'hijos' de un elemento.
navegacion.removeChild(navegacion.children[2]); //Elimina el elemento de la posición '2' hijo del elemento clase 'navegacion'.