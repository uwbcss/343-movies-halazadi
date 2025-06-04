#include "HistoryCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "Inventory.h"
#include <iostream>

// Registers the HistoryCommand with the CommandFactory
bool HistoryCommand::registered = []() {
  CommandFactory::registerCommand('H', []() { return new HistoryCommand(); });
  return true;
}();

// Constructor for HistoryCommand
HistoryCommand::HistoryCommand() {}

// Executes the history command for a customer
void HistoryCommand::execute(std::istringstream &ss,
                             std::unordered_map<int, Customer *> &customers,
                             Inventory &inventory) {
  (void)inventory;

  int id;
  ss >> id;

  Customer *customer = customers[id];
  if (customer == nullptr) {
    std::cerr << "Invalid customer ID for history: " << id << "\n";
    return;
  }

  customer->printHistory();
}