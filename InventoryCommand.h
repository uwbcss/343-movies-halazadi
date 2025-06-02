#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "Command.h"

class InventoryCommand : public Command {
public:
    InventoryCommand();
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override;

private:
    static bool registered;
};

#endif
