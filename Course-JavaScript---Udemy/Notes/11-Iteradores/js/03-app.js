//Enunciado de ejercicio: debes clasificar los primeros 100 números dependiendo si son 'fizz', 'buzz' o 'fizz buzz'. Los que son múltiples de 3 son 'fizz', si son múltiples de 5 son 'buzz' y si son múltiples de 3 y 5 a la vez son 'fizz buzz'
//Fizz buzz - 100 números

for(let i = 0; i < 100; i++) {
    if(i % 3 === 0 && i % 5 === 0){
        console.log(`${i} fizz buzz`);
        continue;
    }
    if(i % 3 === 0) {
        console.log(`${i} fizz`);
    } else if(i % 5 === 0) {
        console.log(`${i} buzz`);
    }
}