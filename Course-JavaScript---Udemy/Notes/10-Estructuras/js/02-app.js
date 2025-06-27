const puntaje = 1000;
const puntaje2 = '1000';
console.log(typeof puntaje);
console.log(typeof puntaje2);

if (puntaje != puntaje) { //'!=' significa 'diferente a'
    console.log('si es igual');
}


if (puntaje == puntaje2) { //'==' no es estricto a diferencia de '==='
    console.log('si es igual');
}

if (puntaje === puntaje2) { //'===' significa 'igual a (pero de manera estricta)'
    console.log('si es igual');
} else {
    console.log('no es igual');
}