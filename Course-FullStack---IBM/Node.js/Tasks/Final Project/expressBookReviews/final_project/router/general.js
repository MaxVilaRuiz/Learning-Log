const express = require('express');
let books = require("./booksdb.js");
let isValid = require("./auth_users.js").isValid;
let users = require("./auth_users.js").users;
const public_users = express.Router();
const axios = require('axios');


public_users.post("/register", (req,res) => {
  const { username, password } = req.body;

  // Verifica que se hayan enviado ambos campos
  if (!username || !password) {
    return res.status(400).json({ message: "Username and password are required." });
  }

  // Verifica si el usuario ya existe
  const userExists = users.find(user => user.username === username);
  if (userExists) {
    return res.status(409).json({ message: "Username already exists." });
  }

  // Agrega el nuevo usuario
  users.push({ username, password });

  res.status(201).json({ message: "User registered successfully." });
});

// Get the book list available in the shop
// public_users.get('/',function (req, res) {
//   res.send(JSON.stringify({books}, null, 4));
// });

public_users.get("/", async function (req, res) {
  try {
    const data = await promiseCb((resolve) => {
      const booksList = Object.values(books);
      resolve(booksList);
    }, 3000);

    return res.status(200).json(data);
  }
  catch (error) {
    return res.status(500).json({message: "Internal server error"})
  }
})


// Get book details based on ISBN
// public_users.get('/isbn/:isbn',function (req, res) {
//     const isbn = req.params.isbn;
//     res.send(books[isbn]);
//  });

public_users.get("/isbn/:isbn", async function (req, res) {
  try {
    const data = await promiseCb((resolve) => {
      const ibsn = req.params.isbn + "";
      const book = books[isbn];
      resolve(book);
    }, 3000);
    if (data) return res.status(200).json(data);
    return res.status(404).json({message: "Invalid ISBN"})
  }
  catch (error) {
    return res.status(500).json({message: "Internal server error"})
  }
})


// // Get book details based on author
// public_users.get('/author/:author',function (req, res) {
//   // Extract the email parameter from the request URL
//   const author = req.params.author;
//   // Filter the users array to find users whose email matches the extracted email parameter
//   let filtered_books = Object.values(books).filter((book) => book.author === author);
//   // Send the filtered_users array as the response to the client
//   res.send(filtered_books);
// });

public_users.get("/author/:author", async function (req, res) {
  try {
    const data = await promiseCb((resolve) => {
      const author = (req.params.author + "").toLocaleLowerCase();
      const booksList = Object.values(books);
      const newBooks = booksList.filter((book) => 
      book.author.toLocaleLowerCase().match(author));
      resolve(newBook);
    }, 3000);
    if (Array.isArray(data) && data.length) return res.status(200).json(data);
    return res.status(404).json({message: "Invalid ISBN"})
  }
  catch (error) {
    return res.status(500).json({message: "Internal server error"})
  }
})


// Get all books based on title
// public_users.get('/title/:title',function (req, res) {
//   // Extract the email parameter from the request URL
//   const title = req.params.title;
//   // Filter the users array to find users whose email matches the extracted email parameter
//   let filtered_books = Object.values(books).filter((book) => book.title === title);
//   // Send the filtered_users array as the response to the client
//   res.send(filtered_books);
// });

public_users.get("/title/:title", async function (req, res) {
  try {
    const data = await promiseCb((resolve) => {
      const title = (req.params.title + "").toLocaleLowerCase();
      const booksList = Object.values(books);
      const newBooks = booksList.filter((book) => 
      book.title.toLocaleLowerCase().match(title));
      resolve(newBook);
    }, 3000);
    if (Array.isArray(data) && data.length) return res.status(200).json(data);
    return res.status(404).json({message: "Invalid ISBN"})
  }
  catch (error) {
    return res.status(500).json({message: "Internal server error"})
  }
})


//  Get book review
public_users.get('/review/:isbn',function (req, res) {
  const isbn = req.params.isbn;
  res.send(books[isbn].reviews);
});

module.exports.general = public_users;
