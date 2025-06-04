#include "MovieFactory.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Utils.h"
#include <cctype>
#include <iostream>
#include <sstream>

// Creates a Movie object from a line of text, based on movie type
Movie *MovieFactory::createMovie(const std::string &line) {
  if (line.empty() || trim(line).empty()) {
    return nullptr;
  }

  std::istringstream ss(line);
  char type;
  ss >> type;

  if (ss.fail()) {
    std::cerr << "Invalid movie line (cannot read type): " << line << "\n";
    return nullptr;
  }

  ss.ignore(2); // skip comma and space

  std::string temp;
  int stock = 0;

  std::string director;
  std::string title;
  std::string actorFirst;
  std::string actorLast;
  int year = 0;
  int month = 0;

  switch (type) {
  case 'F': {
    if (!std::getline(ss, temp, ',')) {
      break;
    }
    temp = trim(temp);
    if (temp.empty() || !std::all_of(temp.begin(), temp.end(), ::isdigit)) {
      break;
    }
    stock = std::stoi(temp);

    if (!std::getline(ss, director, ',')) {
      break;
    }
    director = trim(director);

    if (!std::getline(ss, title, ',')) {
      break;
    }
    title = trim(title);

    ss >> year;
    if (ss.fail()) {
      break;
    }

    return new Comedy(stock, director, title, year);
  }

  case 'D': {
    if (!std::getline(ss, temp, ',')) {
      break;
    }
    temp = trim(temp);
    if (temp.empty() || !std::all_of(temp.begin(), temp.end(), ::isdigit)) {
      break;
    }
    stock = std::stoi(temp);

    if (!std::getline(ss, director, ',')) {
      break;
    }
    director = trim(director);

    if (!std::getline(ss, title, ',')) {
      break;
    }
    title = trim(title);

    ss >> year;
    if (ss.fail()) {
      break;
    }

    return new Drama(stock, director, title, year);
  }

  case 'C': {
    if (!std::getline(ss, temp, ',')) {
      break;
    }
    temp = trim(temp);
    if (temp.empty() || !std::all_of(temp.begin(), temp.end(), ::isdigit)) {
      break;
    }
    stock = std::stoi(temp);

    if (!std::getline(ss, director, ',')) {
      break;
    }
    director = trim(director);

    if (!std::getline(ss, title, ',')) {
      break;
    }
    title = trim(title);

    ss >> actorFirst >> actorLast >> month >> year;
    if (ss.fail()) {
      break;
    }

    return new Classic(stock, director, title, actorFirst + " " + actorLast,
                       month, year);
  }

  default:
    if (type != ' ') {
      std::cerr << "Unknown movie type: " << type
                << ", discarding line: " << line << "\n";
    }
    return nullptr;
  }

  std::string trimmed = trim(line);
  if (!trimmed.empty()) {
    std::cerr << "Invalid movie line: " << trimmed << "\n";
  }

  return nullptr;
}
