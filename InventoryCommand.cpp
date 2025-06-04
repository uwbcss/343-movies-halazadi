#include "InventoryCommand.h"
#include "CommandFactory.h"
#include "Customer.h"
#include "Inventory.h"
#include <iostream>

// Registers the InventoryCommand with the CommandFactory
bool InventoryCommand::registered = []() {
  CommandFactory::registerCommand('I', []() { return new InventoryCommand(); });
  return true;
}();

// Constructor for InventoryCommand
InventoryCommand::InventoryCommand() {}

// Executes the inventory command to print the inventory
void InventoryCommand::execute(std::istringstream &ss,
                               std::unordered_map<int, Customer *> &customers,
                               Inventory &inventory) {
  (void)ss;        // Mark unused parameter as intentionally unused
  (void)customers; // Mark unused parameter as intentionally unused
  inventory.printInventory();
}