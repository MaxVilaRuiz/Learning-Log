//Condición 'Or' (||):

const efectivo = 300;
const credito = 100;
const disponible = efectivo + credito;
const totalPagar = 600;

if( efectivo > totalPagar || credito > totalPagar || disponible > totalPagar) { //Solo con que una condición sea 'true' el resultado del parentesis del 'if' será 'true'
    console.log('Si podemos pagar');
} else{
    console.log('Fondos Insuficientes');
}
