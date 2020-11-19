#!/usr/bin/node
const request = require('request');

const mid = process.argv[2];
const url = `https://swapi.dev/api/films/${mid}/`;
request(url, async function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const char of characters) {
      const res = await new Promise((resolve, reject) => {
        request(char, (error, res, html) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(res);
    }
  }
});
