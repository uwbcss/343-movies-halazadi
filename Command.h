#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <unordered_map>
#include <sstream>

class Customer;
class Inventory;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(std::istringstream& ss,
                         std::unordered_map<int, Customer*>& customers,
                         Inventory& inventory) = 0;
};

#endif
