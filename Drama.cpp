#include "Drama.h"
#include "Inventory.h"
#include <algorithm>
#include <iostream>
#include <vector>

Drama::Drama(int stock, const std::string &director, const std::string &title,
             int year)
    : Movie('D', stock, director, title, year) {} // Drama constructor

std::string Drama::getKey() const {
  return director + "|" + title;
} // Returns the unique key

void Drama::printInfo() const {
  // Prints information about the drama movie
  std::cout << "[Drama] " << stock << " | " << director << " | " << title
            << " | " << year << "\n";
}

void Drama::printInventory(const Inventory &inventory) {
  // Prints all drama movies in the inventory
  std::vector<Movie *> movies = inventory.getAllMoviesOfGenre('D');

  std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {
    if (a->getDirector() == b->getDirector()) {
      return a->getTitle() < b->getTitle();
    }
    return a->getDirector() < b->getDirector();
  });

  for (const auto &movie : movies) {
    movie->printInfo();
  }
}
