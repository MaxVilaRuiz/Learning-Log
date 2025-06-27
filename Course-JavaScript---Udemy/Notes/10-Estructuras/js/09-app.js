//Aunque es mejor usar 'if' para las condiciones también puedes usar este tipo de estructura de código:

const autenticado = true;
const puedePagar = true;

console.log(autenticado && puedePagar ? 'Si esta autenticado' : 'No esta autenticado'); //Recordatorio: '&&' = and | '?' = var es igual a 'true'? | ':' si no es 'true', ejecuta lo siguiente...
console.log(autenticado ? puedePagar ? 'Si esta autenticado y puede pagar' : 'Si autenticado, no puede pagar' : 'No no esta autenticado'); //Manera más compleja de hacer líneas  4 y 5. Traducción de línea 7: si esta autenticado, se mira si puede pagar, si no esta autenticado imprime 'No no esta autenticado'. Si esta autenticado y puede pagar, imprime 'Si esta autenticado y puede pagar'. Si esta autenticado pero no puede pagar, imprime 'Si autenticado, no puede pagar'.