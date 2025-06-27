//Condición 'And' (&&):

const usuario = false;
const puedePagar = true;

if (usuario && puedePagar) { //'&&' = and / y. Si la condición A y la condición B se cumplen, ejecuta el codigo, si no...
    console.log('Si eres usuario');
} else if (!usuario) { //'(!condicion)' = si la condición es falsa (if not(...))...
    console.log('Inicia sesión o saca una cuenta');
} else if (!puedePagar) {
    console.log('Fondos Insuficientes');
} else if (!puedePagar && !usuario) {
    console.log('No puedes comprar');
}