#include "Inventory.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "MovieFactory.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// Constructor for Inventory
Inventory::Inventory() {}

// Destructor for Inventory
Inventory::~Inventory() {
  for (auto &genrePair : moviesByGenre) {
    for (auto &moviePair : genrePair.second) {
      delete moviePair.second;
    }
  }
}

// Loads movies from a file into the inventory
void Inventory::loadFromFile(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;

  while (getline(file, line)) {
    if (line.empty() ||
        line.find_first_not_of(" \t\r\n") == std::string::npos) {
      continue;
    }

    Movie *movie = MovieFactory::createMovie(line);
    if (movie != nullptr) {
      addMovie(movie);
    }
  }
}

// Prints all movies in the inventory
void Inventory::printInventory() const {
  for (const char genre : {'F', 'D', 'C'}) {
    auto it = moviesByGenre.find(genre);
    if (it != moviesByGenre.end()) {
      std::vector<Movie *> movies;
      for (const auto &pair : it->second) {
        movies.push_back(pair.second);
      }

      // Sort depending on genre
      if (genre == 'F') {
        std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {
          return (a->getTitle() != b->getTitle())
                     ? a->getTitle() < b->getTitle()
                     : a->getYear() < b->getYear();
        });
      } else if (genre == 'D') {
        std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {
          return (a->getDirector() != b->getDirector())
                     ? a->getDirector() < b->getDirector()
                     : a->getTitle() < b->getTitle();
        });
      } else if (genre == 'C') {
        std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {
          Classic *ca = dynamic_cast<Classic *>(a);
          Classic *cb = dynamic_cast<Classic *>(b);
          if (ca != nullptr && cb != nullptr) {
            if (ca->getYear() != cb->getYear()) {
              return ca->getYear() < cb->getYear();
            }
            if (ca->getMonth() != cb->getMonth()) {
              return ca->getMonth() < cb->getMonth();
            }
            return ca->getMajorActor() < cb->getMajorActor();
          }
          return false;
        });
      }

      // Print all
      for (const auto &movie : movies) {
        movie->printInfo();
      }
    }
  }
}

// Returns a pointer to a movie with the given key
Movie *Inventory::getMovie(const std::string &key) const {
  for (const auto &genrePair : moviesByGenre) {
    for (const auto &moviePair : genrePair.second) {
      if (moviePair.first == key) {
        return moviePair.second;
      }
    }
  }
  return nullptr;
}

// Adds a movie to the inventory
void Inventory::addMovie(Movie *movie) {
  moviesByGenre[movie->getGenre()][movie->getKey()] = movie;
}

// Gets all movies of a specific genre
std::vector<Movie *> Inventory::getAllMoviesOfGenre(char genre) const {
  std::vector<Movie *> result;
  auto it = moviesByGenre.find(genre);
  if (it != moviesByGenre.end()) {
    for (const auto &pair : it->second) {
      result.push_back(pair.second);
    }
  }
  return result;
}