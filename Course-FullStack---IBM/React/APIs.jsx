import { useEffect, useState } from "react";


const ConnectToServer = () => {
    useEffect(() => { // React Hook used for performing side effects (async functions)
        fetch('https://directionoftheapi.com') // Start the interaction with the API
        .then(response => response.json) // Treat the response of the API as a .json
        .then(data => { // Treat the data receaved from the API
            console.log(data);
            // Do whatever you want with the data
        })
        .catch(error => { // Treat an error if occurres
            console.error('An error has occurred: ', error);
            // Do whatever you want with the error
        });
    })
}


// Run 'npm install axios' in the terminal
import axios from 'axios';
const ConnectToServer_Axios = () => {
    useEffect(() => {
        axios.get('https://directionoftheapi.com') // Start the interaction with the API
        .then(response => { // Treat the response of the API as a .json and receave the data
            console.log(response.data);
            // Do whatever you want with the data (response.data)
        })
        .catch(error => { // Treat an error if occurres
            console.error('An error has occurred: ', error);
            // Do whatever you want with the error
        });
    })
}
 

export default ConnectToServer;
// export default ConnectToServer_Axios;