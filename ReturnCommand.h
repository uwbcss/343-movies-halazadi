#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "Command.h"

class ReturnCommand : public Command {
public:
    ReturnCommand(); // Constructor for ReturnCommand
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override; // Executes the return command

private:
    static bool registered; // Registration flag for CommandFactory
};

#endif