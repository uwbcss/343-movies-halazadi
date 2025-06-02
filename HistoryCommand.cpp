#include "HistoryCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include <iostream>

bool HistoryCommand::registered = []() {
  CommandFactory::registerCommand('H', []() { return new HistoryCommand(); });
  return true;
}();

HistoryCommand::HistoryCommand() {}

void HistoryCommand::execute(std::istringstream &ss,
                             std::unordered_map<int, Customer *> &customers,
                             Inventory &) {
  int id;
  ss >> id;

  Customer *customer = customers[id];
  if (!customer) {
    std::cerr << "Invalid customer ID for history: " << id << "\n";
    return;
  }

  customer->printHistory();
}
