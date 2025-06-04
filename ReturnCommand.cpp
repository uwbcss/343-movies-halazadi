#include "ReturnCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "Inventory.h"
#include "Movie.h"
#include "Utils.h"
#include <iostream>

// Registers the ReturnCommand with the CommandFactory
bool ReturnCommand::registered = []() {
  CommandFactory::registerCommand('R', []() { return new ReturnCommand(); });
  return true;
}();

// Constructor for ReturnCommand
ReturnCommand::ReturnCommand() {}

// Executes the return command for a customer returning a movie
void ReturnCommand::execute(std::istringstream &ss,
                            std::unordered_map<int, Customer *> &customers,
                            Inventory &inventory) {
  int id;
  char media;
  char genre;
  ss >> id >> media >> genre;

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
    int year = 0;
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
    int month = 0;
    int year = 0;
    std::string first;
    std::string last;
    ss >> month >> year >> first >> last;
    movieKey = std::to_string(month) + "|" + std::to_string(year) + "|" +
               first + " " + last;
  } else {
    std::cout << "Invalid movie type: " << genre << "\n";
    std::cout << "Failed to execute command: Return " << customer->getName()
              << " UnknownMovie\n";
    return;
  }

  Movie *movie = inventory.getMovie(movieKey);
  if (movie == nullptr || movie->getGenre() != genre) {
    std::cout << "Invalid movie or genre not found for key: " << movieKey
              << "\n";
    std::cout << "Failed to execute command: Return " << customer->getName()
              << " UnknownMovie\n";
    return;
  }

  if (!customer->hasBorrowedMovie(movieKey)) {
    std::cout << customer->getName() << " could NOT return "
              << movie->getTitle() << ", was not checked out:\n";
    std::cout << "Failed to execute command: Return " << customer->getName()
              << " " << movie->getTitle() << "\n";
    return;
  }

  customer->removeBorrowedMovie(movieKey);
  movie->increaseStock();
  customer->addTransaction("Returned: " + movie->getTitle());
}
