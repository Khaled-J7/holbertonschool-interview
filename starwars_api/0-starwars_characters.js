#!/usr/bin/node
const request = require('request');

// Function to get movie characters
function getMovieCharacters (movieId) {
  // Define the base URL for the Star Wars API
  const baseUrl = 'https://swapi.dev/api/films/';

  // Construct the URL for the given movie ID
  const movieUrl = `${baseUrl}${movieId}/`;

  // Fetch movie details from the API
  request(movieUrl, (error, response, body) => {
    if (error) {
      console.error('Error fetching movie data:', error);
      return;
    }

    if (response.statusCode !== 200) {
      console.error('Failed to fetch movie data:', response.statusCode);
      return;
    }

    const movieData = JSON.parse(body);

    // Get the list of characters from the movie data
    const characterUrls = movieData.characters;

    // Fetch and print each character's name
    characterUrls.forEach(characterUrl => {
      request(characterUrl, (error, response, body) => {
        if (error) {
          console.error('Error fetching character data:', error);
          return;
        }

        if (response.statusCode !== 200) {
          console.error('Failed to fetch character data:', response.statusCode);
          return;
        }

        const characterData = JSON.parse(body);
        console.log(characterData.name);
      });
    });
  });
}

// Check if the script is being run with the correct arguments
if (process.argv.length !== 3) {
  console.log('Usage: node script.js <movie_id>');
  process.exit(1);
}

// Get the movie ID from the command line arguments
const movieId = process.argv[2];
if (isNaN(movieId)) {
  console.log('Movie ID should be a number');
  process.exit(1);
}

// Call the function to get and print character names
getMovieCharacters(movieId);
