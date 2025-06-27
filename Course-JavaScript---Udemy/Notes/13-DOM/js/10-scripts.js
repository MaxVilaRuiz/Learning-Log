//Para crear un nuevo enlace desde el DOM:

const enlace = document.createElement('A') //Entre los '('')' pones la etiqueta del elemento que quieras crear. Ex: img...
enlace.textContent = 'Nuevo Enlace'; //Agregando el texto.
enlace.href = 'nuevo-enlace'; //Añadiendo 'href' (hipervinculo).
enlace.target = '_blank'; //Para que cuando le des click al enlace, te abra en una ventana nueva.
enlace.setAttribute('data-enlace', 'nuevo-enlace');
enlace.classList.add('alguna-clase'); //Para agregar una clase en un elemento (en este caso la clase creada se llama 'alguna-clase').
enlace.onclick = miFuncion; //'onclick' sirve para asignarle un valor cuando le des click al enlace.
console.log(enlace);
//Para seleccionar la navegacion:
const navegacion = document.querySelector('.navegacion');
navegacion.appendChild(enlace); //Para agregar un nuevo hijo (en la ultima posición {predeterminado}).
navegacion.insertBefore(enlace, navegacion.children[1]); //Esta agregando un nuevo hijo pero en la posición que uno desee. En este caso es antes de la posición '1'. Estructura: (que quieres agregar, antes de que posicion i de que elemento lo quieres agregar).

//Para que salga una alerta cuando hagas click (se ha puesto el nombre de la funcion en la línea 9 para que lo ejecute en la 2 pasada (remember)):
function miFuncion(){
    alert('Diste click');
}



//Crear un CARD / targeta de la página:

//Creamos los textos:
const parrafo1 = document.createElement('P');
parrafo1.textContent = 'Concierto';
parrafo1.classList.add('categoria', 'concierto'); //Agrega 2 clases en 'parrafo1' con nombres ''categoria', 'concierto''.
const parrafo2 = document.createElement('P');
parrafo2.textContent = 'Concierto de Rock';
parrafo2.classList.add('titulo');
const parrafo3 = document.createElement('P');
parrafo3.textContent = '800€ por persona';
parrafo3.classList.add('precio');

//Creamos la información a partir de los textos anteriores:
const info = document.createElement('div'); //Creamos un div con la etiqueta 'div'.
info.classList.add('info'); //Le asignamos una clase con nombre específico.
info.appendChild(parrafo1);
info.appendChild(parrafo2);
info.appendChild(parrafo3);
console.log(parrafo1, parrafo2, parrafo3);

//Creamos una imagen:
const imagen = document.createElement('img'); //Creamos elemento de tipo imagen con la etiqueta 'img'.
imagen.src = 'img/hacer2.jpg'; //Le assignamos el nombre del documento de la imagen que le queremos agregar (tiene que estar ya agregado en el archivo de trabajo (este workspace)).

//Creamos el card:
const card = document.createElement('div');
card.classList.add('card');
card.appendChild(imagen); //Le añadimos la imagen
card.appendChild(info); //Le añadimos la información

//Asignar en HTML:
const contenedor = document.createElement('.hacer .contenedor-cards');
contenedor.appendChild(card);
contenedor.insertBefore(card, contenedor.children[0]);