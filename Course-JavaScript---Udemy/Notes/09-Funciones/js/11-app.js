const aprendiendo = function(tecnologia, tecnologia2) {
    console.log(`Aprendiendo ${tecnologia} y ${tecnologia2}`);
}
aprendiendo('JavaScript', 'Node.js');

const aprendiendo2 = tecnologia => `Aprendiendo ${tecnologia}`; //En los Arrow Functions si solo quieres poner un parametro puedes ponerlo sin los parentesis (como esta puesto)
const aprendiendo3 = (tecnologia, tecnologia2) => `Aprendiendo ${tecnologia} y ${tecnologia2}`; //Si hay más de un parametro debes ponerlos entre parentesis
console.log(aprendiendo3('JavaScript', 'Node.js')); //Otra manera de hacer línea 1,2,3 y 4