#include "BorrowCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "Inventory.h"
#include "Movie.h"
#include "Utils.h"
#include <iostream>

// BorrowCommand Check
bool BorrowCommand::registered = []() {
  CommandFactory::registerCommand('B', []() { return new BorrowCommand(); });
  return true;
}();

BorrowCommand::BorrowCommand() = default; // BorrowCommand constructor

void BorrowCommand::execute(std::istringstream &ss,
                            std::unordered_map<int, Customer *> &customers,
                            Inventory &inventory) {
  // Executes the borrow logic for a customer and movie

  int id;
  ss >> id;

  char media;
  ss >> media;

  char genre;
  ss >> genre;

  if (media != 'D') {
    std::cout << "Unsupported media type: " << media << "\n";
    return;
  }

  Customer *customer = customers[id];
  if (customer == nullptr) {
    std::cout << "Invalid customer ID: " << id << "\n";
    return;
  }

  std::string movieKey;

  if (genre == 'F') {
    std::string title;
    int year;
    std::getline(ss, title, ',');
    ss >> year;
    movieKey = trim(title) + "|" + std::to_string(year);
  } else if (genre == 'D') {
    std::string director;
    std::getline(ss, director, ',');
    std::string title;
    std::getline(ss, title, ',');
    movieKey = trim(director) + "|" + trim(title);
  } else if (genre == 'C') {
    int month;
    int year;
    std::string first;
    std::string last;
    ss >> month >> year >> first >> last;
    movieKey = std::to_string(month) + "|" + std::to_string(year) + "|" +
               first + " " + last;
  } else {
    std::cout << "Invalid movie type: " << genre << "\n";
    return;
  }

  Movie *movie = inventory.getMovie(movieKey);
  if (movie == nullptr || movie->getGenre() != genre) {
    std::cout << "Invalid movie or genre not found for key: " << movieKey
              << "\n";
    return;
  }

  if (!movie->decreaseStock()) {
    std::cout << customer->getName() << " could NOT borrow "
              << movie->getTitle() << ", out of stock:\n";
    std::cout << "Failed to execute command: Borrow " << customer->getName()
              << " " << movie->getTitle() << "\n";
    return;
  }

  customer->addBorrowedMovie(movieKey);
  customer->addTransaction("Borrowed: " + movie->getTitle());
}
