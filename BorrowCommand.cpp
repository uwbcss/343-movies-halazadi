#include "BorrowCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "Inventory.h"
#include "Movie.h"
#include "Utils.h"
#include <iostream>

bool BorrowCommand::registered = []() {
  CommandFactory::registerCommand('B', []() { return new BorrowCommand(); });
  return true;
}();

BorrowCommand::BorrowCommand() {}

void BorrowCommand::execute(std::istringstream &ss,
                            std::unordered_map<int, Customer *> &customers,
                            Inventory &inventory) {
  int id;
  char media, genre;
  ss >> id >> media >> genre;
  if (media != 'D') {
    std::cerr << "Unsupported media type: " << media << "\n";
    return;
  }

  Customer *customer = customers[id];
  if (!customer) {
    std::cerr << "Invalid customer ID: " << id << "\n";
    return;
  }

  std::string movieKey;

  if (genre == 'F') {
    std::string title;
    int year;
    getline(ss, title, ',');
    ss >> year;
    movieKey = trim(title) + "|" + std::to_string(year);
  } else if (genre == 'D') {
    std::string director;
    getline(ss, director, ',');
    std::string title;
    getline(ss, title, ',');
    movieKey = trim(director) + "|" + trim(title);
  } else if (genre == 'C') {
    int month, year;
    std::string first, last;
    ss >> month >> year >> first >> last;
    movieKey = std::to_string(month) + "|" + std::to_string(year) + "|" +
               first + " " + last;
  } else {
    std::cerr << "Invalid movie type: " << genre << "\n";
    return;
  }

  Movie *movie = inventory.getMovie(movieKey);
  if (!movie || movie->getGenre() != genre) {
    std::cerr << "Invalid movie or genre not found for key: " << movieKey
              << "\n";
    return;
  }

  if (!movie->decreaseStock()) {
    std::cerr << "Movie out of stock: " << movie->getTitle() << "\n";
    return;
  }

  customer->addTransaction("Borrowed: " + movie->getTitle());
}
