const producto = 'Monitor 20 pulgadas';
console.log(producto);

//.replace() para remplazar palabras: (palabra a remplazar, palabra substitutoria)
console.log(producto.replace('Pulgadas', '"'));
console.log(producto.replace('Monitor', 'Monitor Curvo'));

//.slice para cortar (inicio, final) <-- del recorte
console.log(producto.slice(0, 10)); //De la posición 0 hasta la 10 (recortar)
console.log(producto.substring(2, 1)); //No te funciona, con .substring() sí.
console.log(producto.slice(8)); //De la posición 8 hasta el final (recorta)

//Alternativa a slice --> .substring(posición, cortar x caracteres). Són iguales, menos porque .subtring() te funciona si le colocas de inicio un número mayor que el posterior
console.log(producto.substring(0, 10));
console.log(producto.substring(2, 1));
const ususario = 'Max';
console.log(usuario.subtring(0, 1));

//.charAT(x) sirve para que te imprima la posición "x" de String. También se puede con: console.log(usuario[0])
console.log(usuario.charAt(0));