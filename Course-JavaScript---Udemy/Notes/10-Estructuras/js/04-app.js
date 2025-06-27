const dinero = 300;
const totalAPagar = 500;
const targeta = false;
const cheque = true;

if (dinero >= totalAPagar) {
    console.log('Si puedes pagarlo');
} else if(targeta){ //
    console.log('Si puedo pagar porque tengo la targeta'); //Si no se cumple la condición del if pasará al 'else if (elif)' y en orden consecutivo hasta llegar al 'else' (en caso que no se cumpla ninguna de las condiciones anteriores)
} else if(cheque){
    console.log('Si tengo cheque');
} else {
    console.log('No puedes pagarlo');
}