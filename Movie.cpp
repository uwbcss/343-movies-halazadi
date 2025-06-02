#include "Movie.h"

Movie::Movie(char genre, int stock, const std::string &director,
             const std::string &title, int year)
    : genre(genre), stock(stock), director(director), title(title), year(year) {
}

char Movie::getGenre() const { return genre; }

int Movie::getStock() const { return stock; }

void Movie::increaseStock() { ++stock; }

bool Movie::decreaseStock() {
  if (stock > 0) {
    --stock;
    return true;
  }
  return false;
}

std::string Movie::getTitle() const { return title; }

std::string Movie::getDirector() const { return director; }

int Movie::getYear() const { return year; }
