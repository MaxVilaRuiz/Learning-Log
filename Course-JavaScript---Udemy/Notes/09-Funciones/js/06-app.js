//Valores por defecto:
function saludar(nombre = 'Desconocido', apellido = 'no tiene apellido') { //Si no hay valor en nombre o apellido cuando se llama la función, nombre o apellido va a tener el valor de 'Desconocido' o 'no tiene apellido' (correspondiendo a que argumento falte) <-- Valor por defecto
    console.log(`Hola ${nombre} ${apellido}`);
}
saludar('Max');