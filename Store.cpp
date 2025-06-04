#include "Store.h"
#include "CommandFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor initializes inventory
Store::Store() { inventory = new Inventory(); }

// Destructor cleans up inventory and customer memory
Store::~Store() {
  delete inventory;
  for (auto &pair : customers) {
    delete pair.second;
  }
}

// Loads customers from a file and stores them in the map
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

// Loads movie inventory from a file
void Store::loadInventory(const std::string &filename) {
  inventory->loadFromFile(filename);
}

// Processes commands from a file line by line
void Store::processCommands(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;
  while (getline(file, line)) {
    processCommandLine(line);
  }
}

// Parses a command line and executes it
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

// Retrieves a customer by ID
Customer *Store::getCustomer(int id) const {
  auto it = customers.find(id);
  return (it != customers.end()) ? it->second : nullptr;
}
