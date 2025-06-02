#include "Classic.h"
#include <iostream>

Classic::Classic(int stock, const std::string &director,
                 const std::string &title, const std::string &majorActor,
                 int month, int year)
    : Movie('C', stock, director, title, year), majorActor(majorActor),
      releaseMonth(month) {}

std::string Classic::getKey() const {
  return std::to_string(releaseMonth) + "|" + std::to_string(year) + "|" +
         majorActor;
}

void Classic::printInfo() const {
  std::cout << "[Classic] " << stock << " | " << director << " | " << title
            << " | " << majorActor << " | " << releaseMonth << "/" << year
            << "\n";
}
