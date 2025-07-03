// Def: an object returned by an asynchronoud method
// States: pending, resolved / fulfilled, rejected 


// Example
const methCall = new Promise((resolve, reject) => {
    setTimeout(() => {
        let filename = prompt('What is the name of the file?');
        try {
            const data = fs.readFileSync(filename, {encoding: 'utf8', flag: 'r'});
            resolve(data); // Resolve is called if the promise is achieved. Otherwise, it is executed 'reject'
        }
        catch (err) {
            reject(err);
        }
    }, 3000);
})


// Async / await functions
async function myAsyncFunction() {
    let success = true; // Simulate a situation with a boolean
    if (success) return "The operation was successful!";
    else throw new Error("The operation failed!");
}

async function executeAsyncFunction() { // Using async function to handle promise
    try {
        // Await the async function call to get the result (don't execute anything more while the result is not achieved)
        const result = await myAsyncFunction();
        console.log(result);
    }
    catch (error) {
        console.error(error.message);
    }
}

executeAsyncFunction(); // Call the function to execute



// Axios request
// Def: Package that covers a request with http requests (used to handle http request).
//      Supports CRUD operations and transforms JSON data automatically with a clean and simple API
const axios = require('axios'); // Import Axios library

// Axios - GET request
const connectToURL = (url) => {
    const req = axios.get(url); // 'axios.get()' to make a GET request to a specific URL
    console.log(req);
    req.then(resp => { // Handle success (if the response is successful, the '.then' block is executed)
        // 'resp' obj contains the data returned from the server
        console.log('Fulfilled');
        console.log(resp.data);
    })
    .catch(error => { // Handle error
        console.error('Rejected');
    });
}

// Axios - POST request
const data = { // Data to be sent in the POST request
    name: 'Max Vilà Ruiz',
    age: 19
};
const req = axios.post('https://api.example.com/users', data); // 'axios.post()' to make a POST request to a specific URL
req.then(response => {
    // 'response' obj contains the data returned from the server
    // Treat the data properly if success
})
.catch (error => {
    // Treat the error properly
})

// Axios - Async / await
async function postData() {
    try {
        // Await the response from the Axios POST request
        let response = await axios.post('https://api.example.com/users', {
            title: 'foo',
            body: 'bar',
            userId: 1
        }); 

        console.log(response.data);
    }
    catch (error) {
        console.error(error);
    }
}
postData();