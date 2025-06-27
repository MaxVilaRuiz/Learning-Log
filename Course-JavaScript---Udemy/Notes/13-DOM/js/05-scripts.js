//Query Selector All(como el documento anterior pero te muestra todos los selectores existentes en el documento). QuerySelectorAll no tiene en cuenta si hacemos malas practicas o no.

const card = document.querySelectorAll('.card'); //Sintaxi = 'document.querySelectorAll('x').
console.log(card); //Nos retorna todos los elementos con la clase "card"

//Si un elemento no existe
const noExiste = document.querySelectorAll('no-existe'); // Nos retorna un arreglo que está vacío
console.log(noExiste);