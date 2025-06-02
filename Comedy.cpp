#include "Comedy.h"
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
