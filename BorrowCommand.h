#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "Command.h"

class BorrowCommand : public Command {
public:
    BorrowCommand(); // Constructor for BorrowCommand
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override; // Executes the borrow command

private:
    static bool registered;
};

#endif
