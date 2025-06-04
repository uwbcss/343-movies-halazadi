#include "Classic.h"
#include "Inventory.h"
#include <algorithm>
#include <iostream>
#include <vector>

Classic::Classic(int stock, const std::string &director,
                 const std::string &title, const std::string &majorActor,
                 int month, int year)
    : Movie('C', stock, director, title, year), majorActor(majorActor),
      releaseMonth(month) {} // Classic constructor

std::string Classic::getKey() const {
  // Returns the unique key for the classic movie
  return std::to_string(releaseMonth) + "|" + std::to_string(year) + "|" +
         majorActor;
}

void Classic::printInfo() const {
  // Prints information about the classic movie
  std::cout << "[Classic] " << stock << " | " << director << " | " << title
            << " | " << majorActor << " | " << releaseMonth << " " << year
            << "\n";
}

int Classic::getMonth() const { return releaseMonth; } // Gets the release month

std::string Classic::getMajorActor() const {
  return majorActor;
} // Gets the major actor