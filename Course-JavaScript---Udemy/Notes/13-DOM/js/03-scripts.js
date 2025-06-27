//Solo debes nombrar un ID con el mismo nombre en un documento (en caso que haya más, solo te mostrará un ID {el primero que encuetre}).

//Para buscar IDs en el documento:
const formulario = document.getElementById('formulario');
console.log(formulario);

//En caso que el ID buscado no exista:
const noExiste = document.getElementById/('no-exsite');
console.log(noExiste); //Retorna 'null / nulo'.