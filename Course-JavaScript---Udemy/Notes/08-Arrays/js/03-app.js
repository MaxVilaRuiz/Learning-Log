const meses = ['Enero', 'Febrero', 'Marzo', 'Abril', 'Mayo', 'Junio'];

console.table(meses);
console.table(meses[0]);
console.table(meses[1]);
console.table(meses[2]);

//Cuando mide el Array (var.length) --> method
console.log(meses.length);

//For function --> (let i = x, mientras x algo x, i+x)
for(let i = 0; i < meses.length; i++ ) { //Para repetir 'x' veces un proceso. Creas variable 'i'(item) en 'let' ya que su valor, el qual inicialmente de 0 (en este caso), va a ir canviando. Después dices inicio y fin (mientras i sea menor que meses.length...). Finalmente, dices de cuanto en cuanto va el salto de posición (de uno en uno, de dos en dos o...)
    console.log(meses[i]);
}