//Switch case:

const metodoPago = 'tarjeta';

//Con la estructura 'switch', se revisan los 'case' uno por uno hasta que se cumpla uno, cuando se cumple se ejecuta el codigo dentro del 'case' y, en caso que no lo sea, sigue mirando los otros 'case' hasta llegar al 'default' (en caso que ningún 'case' cumplia la condición)
switch(metodoPago) { //Cuando tienes múltiples condiciones que revisar en una estructura condicional (if, else if...) es más recomendable usar el 'switch'
    case 'efectivo':
        pagar();
        console.log(`Pagaste con ${metodoPago}`);
        break; //Cuando termines de programar un 'case' debes poner un 'break' al final
    case 'cheque':
        console.log(`Pagaste con ${metodoPago}`);
        break;
    case 'tarjeta':
        console.log(`Pagaste con ${metodoPago}`);
        break; 
    default: //En la estructura 'switch' no son obligatorios los 'case' pero si lo es el 'default'
        console.log('Aún no has seleccionado un método de pago');
        break; //Al terminar un 'default' también debes poner un 'break'
}

function pagar() {
    console.log('Pagando...');
}