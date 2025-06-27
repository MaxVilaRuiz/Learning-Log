const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio', 'Julio'];
meses[0] = 'Nuevo Mes'; //Los valores internos de los Arrays pueden ser modificados aunque el Array sea definida con 'const'
meses[10] = 'Ultimo Mes'; //Si añades un valor a una posición del Array que no ha sido definida, puedes añadirlo correctamente y te respetará los espacios que vaya hasta esa posición / valor
console.table(meses);