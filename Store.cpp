#include "Store.h"
#include "CommandFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>

Store::Store() { inventory = new Inventory(); }

Store::~Store() {
  delete inventory;
  for (auto &pair : customers) {
    delete pair.second;
  }
}

void Store::loadCustomers(const std::string &filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Failed to open customers file.\n";
    return;
  }

  int id;
  std::string first;
  std::string last;
  while (file >> id >> last >> first) {
    customers[id] = new Customer(id, first, last);
  }
}

void Store::loadInventory(const std::string &filename) {
  inventory->loadFromFile(filename);
}

void Store::processCommands(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;
  while (getline(file, line)) {
    processCommandLine(line);
  }
}

void Store::processCommandLine(const std::string &line) {
  std::istringstream ss(line);
  char commandType;
  ss >> commandType;

  Command *command = CommandFactory::create(commandType);
  if (command != nullptr) {
    command->execute(ss, customers, *inventory);
    delete command;
  } else {
    std::cerr << "Invalid command: " << commandType << "\n";
  }
}

Customer *Store::getCustomer(int id) const {
  auto it = customers.find(id);
  return (it != customers.end()) ? it->second : nullptr;
}
