// Routing:
//  - Requests to different routes
//  - Use GET, POST, PUT, DELETE methods
//  - Recommended: use routers & organize the code into sections separated by the different routes and requests

const express = require('express');
const app = new express();

// Example without routers:
app.get("user/about/:id", (req, res) => {
    res.send(req.params.id);
})
app.post("user/about/:id", (req, res) => {
    res.send(req.params.id);
})

app.get("item/about/:id", (req, res) => {
    res.send(req.params.id);
})
app.post("item/about/:id", (req, res) => {
    res.send(req.params.id);
})

app.listen(3333, () => {
    console.log(`Listening at http://localhost:3333`)
})

// Example with routers:
let userRouter = express.Router();
let itemRouter = express.Router();

app.use("/item", itemRouter);
app.use("/user", userRouter);

userRouter.get("/about/:id", (req, res) => {
    res.send(req.params.id);
})
userRouter.post("/about/:id", (req, res) => {
    res.send(req.params.id);
})

itemRouter.get("/about/:id", (req, res) => {
    res.send(req.params.id);
})
itemRouter.post("/about/:id", (req, res) => {
    res.send(req.params.id);
})

app.listen(3333, () => {
    console.log(`Listening at http://localhost:3333`)
})



// Middleware:
//  - Functions that have access to the request and response objs and the next function
//  - Categorized based on purpose, use, and source
//  - Useful to parse request, add authentication, handle errors...
//  Bound with: `app.use()`

app.use(function(req, res, next) {
    if (req.query.password !== "pwd123") {
        return res.status(402).send("This user cannot login")
    }
    console.log("Time: ", Date.now())
    next()
})


// Error-handling middleware:
//  - Bound with: `app.use()` or `router.use()`

app.use("/user/:id", function (req, res, next) {
    if (req.params.id == 1) throw new Error ("Trying to access admin login")
    else next()
})
app.use(function(err, req, res, next) {
    if (err != null) res.status(500).send(err.toString())
    else next();
})


// Build-in middleware:
//  - Useful to render static HTML pages by the server, analyse JSON from UI & analyse cookies

app.use(express.static('cad220_staticfiles')) 


// Template rendering
//  - Ability of the server to fill in dynamic content in the HTML template
const expressReactViews = require('express-react-views');
const jsxEngine = expressReactViews.createEngine()

app.set('view engine', 'jsx');
app.set('views', 'myviews')
app.engine('jsx', jsxEngine);

app.get("/:name", (req, res) => {
    res.render('index', {name: req.params.name});
})

// Other React doc:
const React = require('react');
function HelloMessage(props) {
    // return <div>Hello {props.name}</div>;
}
module.exports = HelloMessage;