#include "Inventory.h"
#include "MovieFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>

Inventory::Inventory() {}

Inventory::~Inventory() {
  for (auto &genrePair : moviesByGenre) {
    for (Movie *m : genrePair.second) {
      delete m;
    }
  }
}

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

void Inventory::printInventory() const {
  for (const auto &genre : {"F", "D", "C"}) {
    auto it = moviesByGenre.find(genre);
    if (it != moviesByGenre.end()) {
      for (Movie *m : it->second) {
        m->printInfo();
      }
    }
  }
}

Movie *Inventory::getMovie(const std::string &key) const {
  for (const auto &genrePair : moviesByGenre) {
    for (Movie *m : genrePair.second) {
      if (m->getKey() == key) {
        return m;
      }
    }
  }
  return nullptr;
}

void Inventory::addMovie(Movie *movie) {
  std::string genre(1, movie->getGenre());
  moviesByGenre[genre].push_back(movie);
}
