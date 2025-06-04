#include "Customer.h"
#include <iostream>

Customer::Customer(int id, const std::string &first, const std::string &last)
    : id(id), firstName(first), lastName(last) {} // Constructor for Customer

Customer::~Customer() {} // Destructor for Customer

int Customer::getID() const {
  // Returns the customer ID
  return id;
}

std::string Customer::getName() const {
  // Returns the full customer name
  return firstName + " " + lastName;
}

void Customer::addTransaction(const std::string &transaction) {
  // Adds a transaction to the customer's history
  history.push_back(transaction);
}

void Customer::printHistory() const {
  // Prints the customer's transaction history
  std::cout << "History for " << getName() << " (ID: " << id << "):\n";
  if (history.empty()) {
    std::cout << "  No history for " << getName() << "\n";
  } else {
    for (const std::string &record : history) {
      std::cout << "  " << record << "\n";
    }
  }
}

void Customer::addBorrowedMovie(const std::string &movieKey) {
  // Adds a movie key to the set of borrowed movies
  borrowedMovies.insert(movieKey);
}

bool Customer::hasBorrowedMovie(const std::string &movieKey) const {
  // Checks if a movie key is in the set of borrowed movies
  return borrowedMovies.find(movieKey) != borrowedMovies.end();
}

void Customer::removeBorrowedMovie(const std::string &movieKey) {
  // Removes a movie key from the set of borrowed movies
  borrowedMovies.erase(movieKey);
}