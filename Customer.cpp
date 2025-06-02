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
    for (const std::string &t : history) {
      std::cout << "  " << t << "\n";
    }
  }
}
