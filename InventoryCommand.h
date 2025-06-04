#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "Command.h"

class InventoryCommand : public Command {
public:
    InventoryCommand(); // Constructor for InventoryCommand
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override; // Executes the inventory command

private:
    static bool registered; // Registration flag for CommandFactory
};

#endif