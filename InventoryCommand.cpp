#include "InventoryCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "Inventory.h"
#include <iostream>

bool InventoryCommand::registered = []() {
  CommandFactory::registerCommand('I', []() { return new InventoryCommand(); });
  return true;
}();

InventoryCommand::InventoryCommand() {}

void InventoryCommand::execute(std::istringstream &,
                               std::unordered_map<int, Customer *> &,
                               Inventory &inventory) {
  inventory.printInventory();
}
