// Declarations
let promise1 = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('First promise is resolved');
    }, 6000);
})

let promise2 = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve('Second promise is resolved');   
    }, 3000);
})

// Async
promise1.then((succesMsg1) => {
    console.log(succesMsg1)
    promise2.then((succesMsg2) => {
        console.log(succesMsg2)
    })
})

// Sequentially
promise1.then((succesMsg1) => {
    console.log(succesMsg1)
})

promise2.then((succesMsg2) => {
    console.log(succesMsg2)
})