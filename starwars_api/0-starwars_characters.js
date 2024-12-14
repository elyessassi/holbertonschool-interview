#!/usr/bin/node

const request = require('request');
const args = process.argv;

const url = `https://swapi-api.hbtn.io/api/films/${args[2]}`;

request(url, (error, response, body) => {
  if (error) {
    return (error);
  }
  if (response.statusMessage === 'NOT FOUND') {
    return (0);
  }
  const film = (JSON.parse(body)).characters;
  film.map((chara) => {
    request(chara, (error, response, body) => {
      if (error) {
        return (error);
      }
      console.log((JSON.parse(body)).name);
    });
    return (0);
  });
});
