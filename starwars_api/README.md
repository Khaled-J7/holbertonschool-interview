# Star Wars API

A script that prints all characters of a Star Wars movie using the Star Wars API.

## Description

This project uses the Star Wars API to fetch and display all characters from a specific Star Wars movie. The script takes a movie ID as input and prints one character name per line in the same order as they appear in the API.

## Requirements

- Node.js 10.14.x
- Request module

## Installation

1. Install Node.js:
```
$ curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```

2. Install the request module:
```
$ sudo npm install request --global
$ export NODE_PATH=/usr/lib/node_modules
```

3. Install semistandard for code linting:
```
$ sudo npm install semistandard --global
```

## Usage

Run the script with a movie ID as an argument:

```
$ ./0-starwars_characters.js <movie_id>
```

Example:
```
$ ./0-starwars_characters.js 3
```

This will print all characters from "Return of the Jedi" (movie ID 3).

## File Structure

- `0-starwars_characters.js`: The main script that fetches and displays Star Wars characters

## Author

__Khaled Jallouli__
