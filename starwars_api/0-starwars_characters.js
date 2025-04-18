#!/usr/bin/node
// Script to print all characters from a Star Wars movie

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// First, get the film data to extract the characters URLs
request(filmUrl, (error, response, body) => {
  if (error) {
    console.error('Error fetching film data:', error);
    process.exit(1);
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Status Code ${response.statusCode}`);
    process.exit(1);
  }

  const filmData = JSON.parse(body);
  const characterUrls = filmData.characters;

  // Using recursive function to fetch characters sequentially to maintain order
  fetchCharactersInOrder(characterUrls, 0);
});

/**
 * Fetches character data in order from an array of URLs
 * @param {Array} urls - Array of character URLs
 * @param {Number} index - Current index in the array
 */
function fetchCharactersInOrder(urls, index) {
  // Base case: all characters have been processed
  if (index >= urls.length) {
    return;
  }

  // Fetch the character at the current index
  request(urls[index], (error, response, body) => {
    if (error) {
      console.error('Error fetching character data:', error);
      process.exit(1);
    }

    if (response.statusCode !== 200) {
      console.error(`Error: Status Code ${response.statusCode}`);
      process.exit(1);
    }

    const characterData = JSON.parse(body);
    console.log(characterData.name);

    // Process the next character
    fetchCharactersInOrder(urls, index + 1);
  });
}
