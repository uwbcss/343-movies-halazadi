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

void InventoryCommand::execute(std::istringstream &ss,
                               std::unordered_map<int, Customer *> &customers,
                               Inventory &inventory) {
  (void)ss;        // Mark unused parameter as intentionally unused
  (void)customers; // Mark unused parameter as intentionally unused
  inventory.printInventory();
}
