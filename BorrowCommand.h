#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "Command.h"

class BorrowCommand : public Command {
public:
    BorrowCommand();
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override;

private:
    static bool registered;
};

#endif
