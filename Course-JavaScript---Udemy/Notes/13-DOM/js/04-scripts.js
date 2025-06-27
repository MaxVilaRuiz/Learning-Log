//Query Selector (nueva manera de buscar clases, IDs y elementos HTML. Solo retorna un elemento de los existentes que se hayan buscado o ninguno en caso que no exista en el documento):

//Para buscar clases se usa '('.clase')'.
const card = document.querySelector('.card');
console.log(card);
//Podemos tener selectores específicos como en CSS:
const info = document.querySelector('.premium .info'); //Si pones un 'espacio' entre las dos clases a la hora de buscarlo, se buscan las clases que contengan las dos clases mostradas (específico).
console.log(info);
const segundoCard = document.querySelector('section.hospedaje'); //Otro ejemplo de buscar de manera específica.
console.log(segundoCard);

//Para buscar IDs:
const formulario = document.querySelector('#formulario');
console.log(formulario);
//También se puede buscar de manera específica IDs:
const formulario2 = document.querySelector('.contenido-hero #formulario');
console.log(formulario2);

//Seleccionar elementos HTML:
const navegacion = document.querySelector('nav');
console.log(navegacion);