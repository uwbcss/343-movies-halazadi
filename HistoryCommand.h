#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "Command.h"

class HistoryCommand : public Command {
public:
    HistoryCommand(); // Constructor for HistoryCommand
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override; // Executes the history command

private:
    static bool registered; // Registration flag for CommandFactory
};

#endif