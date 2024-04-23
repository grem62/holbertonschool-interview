#!/usr/bin/node

const request = require('request');

function getMovieCharacters(movieId) {
    const url = `https://swapi.dev/api/films/${movieId}/`;

    request.get(url, (error, response, body) => {
        if (error) {
            console.error(`Failed to retrieve movie data for movie ID ${movieId}`);
            return;
        }

        if (response.statusCode !== 200) {
            console.error(`Failed to retrieve movie data for movie ID ${movieId}. Status code: ${response.statusCode}`);
            return;
        }

        const data = JSON.parse(body);
        const charactersUrls = data.characters;

        charactersUrls.forEach(characterUrl => {
            request.get(characterUrl, (error, response, body) => {
                if (error) {
                    console.error(`Failed to retrieve character data for ${characterUrl}`);
                    return;
                }

                if (response.statusCode !== 200) {
                    console.error(`Failed to retrieve character data for ${characterUrl}. Status code: ${response.statusCode}`);
                    return;
                }

                const characterData = JSON.parse(body);
                console.log(characterData.name);
            });
        });
    });
}

const movieId = process.argv[2];
getMovieCharacters(movieId);
