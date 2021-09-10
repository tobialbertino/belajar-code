// mengimpor dotenv dan menjalankan konfigurasinya
require('dotenv').config();

const bodyParser = require('body-parser');
const express = require('express');
const app = express();

// Assets at the /public route
app.use("/public", express.static(__dirname + "/public"));

// middleware for all routes
app.use(function middleware(req, res, next) {
  console.log(req.method + " " + req.path + " - " + req.ip);
  next();
});

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());


app.get("/", (req, res) => {
  res.sendFile(__dirname + "/views/index.html");
});

app.get("/json", (req, res) => {
  if (process.env.MESSAGE_STYLE === 'uppercase') {
    res.json(
      {"message": "HELLO JSON"}
      );
    } else {
      res.json(
        {"message": "Hello json"}
      );
  }
});

app.get('/now', (req, res, next) => {
  req.time = new Date().toString();
  next();
},
  (req, res) => {
    res.json(
      {time: req.time}
    )
  }
)

app.get('/:word/echo', (req, res) => {
  const { word } = req.params;
  res.json(
    {echo: word}
  )
})

app.get('/name', (req, res) => {
  const { first: firstName, last: lastName } = req.query;
  res.json(
    {name: `${firstName} ${lastName}`}
  )
})

app.post('/name', (req, res) => {
  const string = req.body.first + ' ' + req.body.last;
  res.json({name: string});
})

module.exports = app;