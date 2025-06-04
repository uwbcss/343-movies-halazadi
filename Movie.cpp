#include "Movie.h"

// Constructor for Movie
Movie::Movie(char genre, int stock, const std::string &director,
             const std::string &title, int year)
    : genre(genre), stock(stock), director(director), title(title), year(year) {
}

// Returns the movie genre
char Movie::getGenre() const { return genre; }

// Returns the number of items in stock
int Movie::getStock() const { return stock; }

// Increases the stock count by one
void Movie::increaseStock() { ++stock; }

// Decreases the stock count by one if possible
bool Movie::decreaseStock() {
  if (stock > 0) {
    --stock;
    return true;
  }
  return false;
}

// Returns the movie title
std::string Movie::getTitle() const { return title; }

// Returns the movie director
std::string Movie::getDirector() const { return director; }

// Returns the movie release year
int Movie::getYear() const { return year; }