#include "MovieFactory.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Utils.h"
#include <cctype>
#include <iostream>
#include <sstream>

Movie *MovieFactory::createMovie(const std::string &line) {
  if (line.empty() || trim(line).empty()) {
    return nullptr; // silently skip completely empty lines
  }

  std::istringstream ss(line);
  char type;
  ss >> type;

  if (ss.fail()) {
    std::cerr << "Invalid movie line (cannot read type): " << line << "\n";
    return nullptr;
  }

  ss.ignore(2); // skip comma and space

  int stock;
  std::string director, title, actorFirst, actorLast;
  int year, month;

  std::string temp;

  switch (type) {
  case 'F': {
    if (!getline(ss, temp, ','))
      break;
    temp = trim(temp);
    if (temp.empty() || !std::all_of(temp.begin(), temp.end(), ::isdigit))
      break;
    stock = std::stoi(temp);

    if (!getline(ss, director, ','))
      break;
    director = trim(director);
    if (!getline(ss, title, ','))
      break;
    title = trim(title);
    ss >> year;

    if (ss.fail())
      break;

    return new Comedy(stock, director, title, year);
  }

  case 'D': {
    if (!getline(ss, temp, ','))
      break;
    temp = trim(temp);
    if (temp.empty() || !std::all_of(temp.begin(), temp.end(), ::isdigit))
      break;
    stock = std::stoi(temp);

    if (!getline(ss, director, ','))
      break;
    director = trim(director);
    if (!getline(ss, title, ','))
      break;
    title = trim(title);
    ss >> year;

    if (ss.fail())
      break;

    return new Drama(stock, director, title, year);
  }

  case 'C': {
    if (!getline(ss, temp, ','))
      break;
    temp = trim(temp);
    if (temp.empty() || !std::all_of(temp.begin(), temp.end(), ::isdigit))
      break;
    stock = std::stoi(temp);

    if (!getline(ss, director, ','))
      break;
    director = trim(director);
    if (!getline(ss, title, ','))
      break;
    title = trim(title);

    ss >> actorFirst >> actorLast >> month >> year;

    if (ss.fail())
      break;

    return new Classic(stock, director, title, actorFirst + " " + actorLast,
                       month, year);
  }

  default:
    if (!isspace(type)) {
      std::cerr << "Unknown movie type: " << type
                << ", discarding line: " << line << "\n";
    }
    return nullptr;
  }

  // Reaching here means parsing failed in some way
  std::string trimmed = trim(line);
  if (!trimmed.empty()) {
    std::cerr << "Invalid movie line: " << trimmed << "\n";
  }
  return nullptr;
}
