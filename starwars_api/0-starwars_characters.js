#!/usr/bin/node

const request = require('request');
const args = process.argv;

const url = `https://swapi-api.hbtn.io/api/films/${args[2]}`;

function getChara () {
  return new Promise((resolve, reject) => {
    try {
      request(url, (error, response, body) => {
        const chars = JSON.parse(body);
        resolve(chars.characters);
        if (error) {
          return (error);
        }
      });
    } catch (error) {
      reject(error);
    }
  });
}

async function ListOfNames () {
  const charL = await getChara();
  for (let i = 0; i < charL.length; i++) {
    await getName(charL[i]);
  }
}

function getName (charurl) {
  return new Promise((resolve, reject) => {
    request(charurl, (error, response, body) => {
      console.log((JSON.parse(body)).name);
      resolve();
      if (error) {
        return (error);
      }
    });
  });
}

ListOfNames();
