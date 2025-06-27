//Seleccionar elementos por su clase..blundleRenderer.renderToStream

const header = document.getElementsByClassName('header'); //Esta almacenando en la variable 'header' el contenido del apartado 'header' en el documento, en caso que exista, ya que lo estamos buscando.
console.log(header);

//Si las clases existen más de una vez, como estas buscando clases te mostrará todos los resultados:
const contenedores = document.getElementsByClassName('contenedor');
console.log(contenedores);

//Si una clase no existe, no te retornará error pero no te retornará nada:
const noExiste = document.getElementsByClassName('no-existe');
console.log(noExiste);