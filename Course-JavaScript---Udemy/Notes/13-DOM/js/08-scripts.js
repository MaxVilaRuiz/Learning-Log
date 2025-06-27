//Traversing the DOM:

//Los 'nodos' = 'href' / enlaces.
const navegacion = document.querySelector('.navegacion');
console.log(navegacion);
console.log(navegacion.firstElementChild); //Para acceder al primer elemento de nav.
console.log(navegacion.lastElementChild); //Para acceder al último elemento del nav.
console.log(navegacion.childNodes); //Los espacios en blanco, son considerados 'elementos'. Consecuentemente, si miras la consola se ven 'a' entre los nodos.
console.log(navegacion.children); //Te muestra elementos reales (para mirar los 'descendientes' de una clase). 

console.log(navegacion.children[1].nodeName); //Te muestra el nombre de manera real de la clase o etiqueta selecionada en la variable.
console.log(navegacion.children[1].nodeType); //Te muestra el tipo de manera real de la clase o etiqueta selecionada en la variable.

const card = document.querySelector('.card');
card.children[1].children[1].textContent = 'Nuevo heading desde traversing the DOM.'; //Modifica con traversing the DOM el elemento específico con la posición mostrada y le assigna otro nombre.
console.log(card.children[1].children[1].textContent); //Llama al elemento con nombre 'card.children[1].children[1].textContent' modificado anteriormente.

card.children[0].src = '/img/hacer2.jpg';
console.log(card.children[0]);

//Traversing the Hijo al padre:
console.log(card.parentNode);
console.log(card.parentElement.parentElement.parentElement); //Es una función más nueva (más recomendable).

//Para viajar hacia el siguinte elemento (el hermano {el del mismo nivel}):
console.log(card);
console.log(card.nextElementSibling); 
console.log(card.nextElementSibling);

//Para viajar al elemento anterior:
const ultimoCard = document.querySelector('card:nth-child(4)');
console.log(ultimoCard.previousElementSibling);