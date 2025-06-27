//DOM = Són todos los elementos de la página web (elementos de HTML). Puedes seleccionar elementos de el mismo y aplicarle modificaciones. En el DOM se tiene acceso a todo el 'documento' en la inspección de la web. 
let elemento;


//Si usas 'document.x' en una variable y la imprimes, te mostrará todo el contenido de esa parte del código HTML.
elemento = document;

elemento = document.all; //Muestra todo el documento.

elemento = document.head;

elemento = document.body; //Muestra el body del documento HTML.

elemento = document.domain; //Para ver la url / I.P de la página web

elemento = document.forms; //Muestra todas las etiquetas 'form / formulario' del documento HTML.
elemento = document.forms[0]; //Muestra el apartado con la posición '0' de las etiquetas 'form'
elemento = document.forms[0].id; //Igual que línea 11 pero con 'ids' también.
elemento = document.forms[0].method; //Igual que línea 11 pero con 'methods' también.

elemento = document.links; //Te muestra todos los enlaces que usa el documento.
elemento = document.links[4]; //También se puede buscar por posición.
elemento = document.links[4].classList; //Te lo retorna en forma de lista (como si fuera un String).
elemento = document.links[4].className; //Te lo retorna en forma de String.

elemento = document.images; //Te dice cuantas imagenes tiene el documento / página web.

elemento = document.scripts; //Te muestra los scripts  del documento.


console.log(elemento);