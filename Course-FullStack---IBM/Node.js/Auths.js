// Authentications methods in Node.js

//  * Session-based:
//      1. User logs in with credentials
//      2. Credentials checked against a DB
//      3. Session ID created & stored in DB and in browser cookies
//      4. Session ID destroyed on logout or expiration
//      Example with Express:

const express = require('express');
const session = require('express-session');
const app = express();

// Middleware to set up session management
app.use(session({
    secret: 'secret-key', // Replace with a strong secret key
    resave: false, // Whether to save the session data if there were no modifications
    saveUninitialized: true, // Whether to save new but not modified sessions 
    cookie: { secure: false } // Set to true in production with HTTPS
}));

// POST endpoint for handling login
app.post('/login', (req, res) => {
    const {username, password} = req.body;
    // Simulated user auth (replace with actual logic)
    if (username === 'user' && password === 'password') {
        req.session.user = username; // Store user information in session
        res.send('Logged in successfully');
    }
    else res.send('Invalid credentials');
})

// GET endpoint for accessing dashboard
app.get('/dashboard', (req, res) => {
    if (req.session.user) res.send(`Welcome ${req.session.user}`) 
})



//  * Token-based:
//      More scalability, flexible and secure
//      1. Authentication: user gets a token
//      2. Authorization: token used to access resources
//      Token contain three parts:
//          - Header: type of token and its algorithm
//          - Payload: includes users' atributes (limit time...)
//          - Signature: ensure the token validation during the transit
//      How it works:
//          1. Browser calls an auth server and interact with it
//          2. Auth server returns and ID token
//          3. Client stores ID token as an encrypted cookie
//          4. Token serves as proof of authentication
//      Example with Express:

const jwt = require('jsonwebtoken');
const bodyParser = require('body-parser');

app.use(bodyParser.json())
const secretKey = 'your-secret-key'; // Replace with a strong secret key

// POST endpoint for user login and JWT generation
app.post('/login', (req, res) => {
    const {username, password} = req.body;
    // Simulated user authentication
    if (username === 'user' && password === 'password') {
        // Generate JWT with username payload
        const token = jwt.sign({username}, secretKey, {expiresIn: '1h'});
        res.json({token}); // Send token as JSON response
    }
    else res.send('Invalid credentials')
})

// GET endpoint to access protected resources (dashboard)
app.get('/dashboard', (req, res) => {
    // Get token from Authorization header
    const token = req.headers['authorization'];
    if (token) {
        // Verify JWT token
    jwt.verify(token, secretKey, (err, decoded) => {
        // ...
    })
    }
})



//  * Passwordless:
//      - Uses biometric, magic links, or one-time passwords
//      - Uses cryptography system
//      Example with Express:

const bodyParser = require('body-parser');
const nodemailer = require('nodemailer');
app.use(bodyParser.json());

const user = {}; // In-memory storage for demo purposes
// Endpoint to request access and send verification code via email
app.post('/request-access', (req, res) => {
    const {email} = req.body;
    // Generate a 6-digit verification code
    const code = Math.floor(100000 + Math.random() * 900000).toString();
    // Store the code in memory (users obj)
    users[email] = code;
    //  Simulated email sending (for demostration)
    console.log(`Sending code ${code} to ${email}`);
    res.send('Code sent to your email')
})

// Endpoint to verify the received code
app.post('/verify-code', (req, res) => {
    const {email, code} = req.body;
    // Compare the received code with stored code for the email
    if (users[email] === code) {
        // Code matches, access granted
        res.send('Access granted')
    }
})



// Creating an authentication Express API server

// Doc "apiServer.js":
const express = require('express');
const myapp = expres();

// Creating a web server module
myapp.get("/employees", (req, res) => {
    return res
        .status(401) // Not autorized
        .json({message: "Please login to access this resource"})
})

myapp.listen(5000, () => {
    console.log("API Server is localhost:5000")
})


// node apiServer.js


// To verify that the endpoint cannot be accessed unless the user is authorized, run:
// curl -i localhost:5000/employee 


// npm install -save jsonwebtoken


// Require the JWT module
const jsonwebtoken = require('jsonwebtoken');
const JWT_SECRET = "aVerySecretString";


// Define POST API method
myapp.use(express.json());
myapp.post("/signin", (req, res) => {
    const {uname, pwd} = req.body; // Example
    // ...
})

// Return the JWT token
if (uname === "user" && pwd === "password") {
    return res.json({
        token: jsonwebtoken.sign({user: "user"}, JWT_SECRET)
    })
}
else return res.status(401).json({message: "Invalid username and / or password"})    

// Define GET API method
myapp.get("/employees", (req, res) => {
    let tkn = req.header('Authorization')
    if (!tkn) return
        res.status(401).send("No Token")
    if (tkn.startWith('Bearer ')) {
        tokenValue = tkn.slice(7, tkn.length).trimLeft()
    }
    // ...

    const verificationStatus = jsonwebtoken.verify(tokenValue, "aVerySecretString");
    if (verificationStatus.user === "user") {
        return res.status(200).json({message: "Access Successful to Employee Endpoint"})
    }
    return res

    .status(401).json({message: "Please login to access this resource"})
})

myapp.listen(5000, () => {
    console.log("API Server is localhost:5000")
})