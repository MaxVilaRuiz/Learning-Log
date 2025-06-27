//Arrow Functions:

const aprendiendo = function() {
    console.log('Aprendiendo JavaScript');
}
aprendiendo();

const aprendiendo2 = () => console.log('Aprendiendo JavaScript'); //Para crear Arrow Functions se elimina el function y en el lado derecho del parentesis poden '=>' y pones el codigo directo SIEMPRE que sea solo de una línea, no hacen falta '{}'.
aprendiendo2(); //Otra manera de hacer línea 3, 4 y 5

const aprendiendo3 = () => 'Aprendiendo JavaScript'; //Otra manera de hacer línea 8 y 9
console.log(aprendiendo3());