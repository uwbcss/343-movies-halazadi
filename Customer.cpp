#include "Customer.h"
#include <iostream>

Customer::Customer(int id, const std::string &first, const std::string &last)
    : id(id), firstName(first), lastName(last) {}

Customer::~Customer() {}

int Customer::getID() const { return id; }

std::string Customer::getName() const { return firstName + " " + lastName; }

void Customer::addTransaction(const std::string &transaction) {
  history.push_back(transaction);
}

void Customer::printHistory() const {
  std::cout << "History for " << getName() << " (ID: " << id << "):\n";
  if (history.empty()) {
    std::cout << "  No history for " << getName() << "\n";
  } else {
    for (const std::string &record : history) {
      std::cout << "  " << record << "\n";
    }
  }
}

// New methods
void Customer::addBorrowedMovie(const std::string &movieKey) {
  borrowedMovies.insert(movieKey);
}

bool Customer::hasBorrowedMovie(const std::string &movieKey) const {
  return borrowedMovies.find(movieKey) != borrowedMovies.end();
}

void Customer::removeBorrowedMovie(const std::string &movieKey) {
  borrowedMovies.erase(movieKey);
}
