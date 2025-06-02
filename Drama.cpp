#include "Drama.h"
#include <iostream>

Drama::Drama(int stock, const std::string &director, const std::string &title,
             int year)
    : Movie('D', stock, director, title, year) {}

std::string Drama::getKey() const { return director + "|" + title; }

void Drama::printInfo() const {
  std::cout << "[Drama] " << stock << " | " << director << " | " << title
            << " | " << year << "\n";
}
