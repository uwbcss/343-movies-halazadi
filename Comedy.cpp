#include "Comedy.h"
#include <algorithm>
#include <iostream>

Comedy::Comedy(int stock, const std::string &director, const std::string &title,
               int year)
    : Movie('F', stock, director, title, year) {}

std::string Comedy::getKey() const {
  return title + "|" + std::to_string(year);
}

void Comedy::printInfo() const {
  std::cout << "[Comedy] " << stock << " | " << director << " | " << title
            << " | " << year << "\n";
}

void Comedy::printInventory(const Inventory &inventory) {
  std::vector<Movie *> movies = inventory.getAllMoviesOfGenre('F');

  std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {
    if (a->getTitle() == b->getTitle()) {
      return a->getYear() < b->getYear();
    }
    return a->getTitle() < b->getTitle();
  });

  for (const auto &movie : movies) {
    movie->printInfo();
  }
}
