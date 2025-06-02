#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "Command.h"

class HistoryCommand : public Command {
public:
    HistoryCommand();
    void execute(std::istringstream& ss,
                 std::unordered_map<int, Customer*>& customers,
                 Inventory& inventory) override;

private:
    static bool registered;
};

#endif
