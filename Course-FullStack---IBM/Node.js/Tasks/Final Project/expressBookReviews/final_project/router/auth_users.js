const express = require('express');
const jwt = require('jsonwebtoken');
let books = require("./booksdb.js");
const regd_users = express.Router();

let users = [];

const isValid = (username)=>{ //returns boolean
//write code to check is the username is valid
}

const authenticatedUser = (username,password)=>{  let validusers = users.filter((user) => {
  return user.username === username && user.password === password;
});
return validusers.length > 0;
}

//only registered users can login
regd_users.post("/login", (req,res) => {
  const username = req.body.username;
  const password = req.body.password;

  if (!username || !password) {
    return res.status(404).json({ message: "Error logging in" });
  }

  if (authenticatedUser(username, password)) {
    let accessToken = jwt.sign({
      data: password
    }, 'access', { expiresIn: 60 * 60 });

    req.session.authorization = {
      accessToken, username
    };
    return res.status(200).send("User successfully logged in");
  } else {
    return res.status(208).json({ message: "Invalid Login. Check username and password" });
  }
});

// Add a book review
regd_users.put("/auth/review/:isbn", (req, res) => {
  const isbn = req.params.isbn;
  const review = req.query.review;

  // Verifica si el usuario está autenticado
  if (!req.session || !req.session.authorization || !req.session.authorization.username) {
    return res.status(401).json({ message: "User not logged in" });
  }

  const username = req.session.authorization.username;

  // Verifica que exista el libro
  if (!books[isbn]) {
    return res.status(404).json({ message: "Book not found" });
  }

  // Verifica que la review esté presente
  if (!review) {
    return res.status(400).json({ message: "Review text is required" });
  }

  // Añade o actualiza la reseña
  books[isbn].reviews[username] = review;

  return res.status(200).json({
    message: "Review added/updated successfully",
    reviews: books[isbn].reviews
  });
});

regd_users.delete("/auth/review/:isbn", (req, res) => {
  const isbn = req.params.isbn;
  const review = req.query.review;

  // Verifica si el usuario está autenticado
  if (!req.session || !req.session.authorization || !req.session.authorization.username) {
    return res.status(401).json({ message: "User not logged in" });
  }

  const username = req.session.authorization.username;

  // Verifica que exista el libro
  if (!books[isbn]) {
    return res.status(404).json({ message: "Book not found" });
  }

  // Verifica que la review esté presente
  if (!review) {
    return res.status(400).json({ message: "Review text is required" });
  }

  // Verifica si existe una review con ese usuario
  if (!books[isbn].reviews[username]) {
    return res.status(400).json({ message: "Review doesn't exist" });
  }

  // Añade o actualiza la reseña
  delete books[isbn].reviews[username];

  return res.status(200).json({
    message: "Review deleted successfully",
  });
})

module.exports.authenticated = regd_users;
module.exports.isValid = isValid;
module.exports.users = users;
