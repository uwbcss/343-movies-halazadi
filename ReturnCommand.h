#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "Command.h"

class ReturnCommand : public Command {
public:
    ReturnCommand();
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override;

private:
    static bool registered;
};

#endif
