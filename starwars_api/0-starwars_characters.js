#!/usr/bin/node
// Script to print all characters from a Star Wars movie

const request = require('request');
const movieId = process.argv[2];

// Check if movie ID was provided
if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1);
}

// URL for the Star Wars API film endpoint
const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Get film data first to extract character URLs
request(filmUrl, (error, response, body) => {
  // Handle potential errors
  if (error) {
    console.error('Error fetching film data:', error);
    process.exit(1);
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Status Code ${response.statusCode}`);
    process.exit(1);
  }

  // Parse the response body to get character URLs
  const filmData = JSON.parse(body);
  const characterUrls = filmData.characters;

  // Process characters one by one in order
  processCharacters(characterUrls, 0);
});

/**
 * Recursively process characters in order
 * @param {Array} urls - Array of character URLs
 * @param {Number} index - Current index in the array
 */
function processCharacters(urls, index) {
  // Base case: all characters have been processed
  if (index >= urls.length) {
    return;
  }

  // Make a request for the current character
  request(urls[index], (error, response, body) => {
    // Handle potential errors
    if (error) {
      console.error('Error fetching character data:', error);
      process.exit(1);
    }

    if (response.statusCode !== 200) {
      console.error(`Error: Status Code ${response.statusCode}`);
      process.exit(1);
    }

    // Parse character data and print the name
    const characterData = JSON.parse(body);
    console.log(characterData.name);

    // Process the next character (recursive call)
    processCharacters(urls, index + 1);
  });
}
