// Def: an object returned by an asynchronoud method
// States: pending, resolved, rejected 


// Example
const methCall = new Promise((resolve, reject) => {
    setTimeout(() => {
        let filename = prompt('What is the name of the file?');
        try {
            const data = fs.readFileSync(filename, {encoding: 'utf8', flag: 'r'});
            resolve(data);
        }
        catch (err) {
            reject(err);
        }
    }, 3000);
})


// Axios request
// Def: Package that covers a request with http requests (used to handle http request). 
// The obj includes a 'then' method that is called after the promise is achieved. 
// If the promise is rejected, the error message is exectuted
const axios = require('axios').default;
const connectToURL = (url) => {
    const req = axios.get(url);
    console.log(req);
    req.then(resp => {
        console.log('Fulfilled');
        console.log(resp.data);
    })
    .catch(error => {
        console.error('Rejected');
    });
}