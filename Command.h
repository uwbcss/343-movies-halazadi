#ifndef COMMAND_H
#define COMMAND_H

#include <sstream>
#include <string>
#include <unordered_map>

class Customer;
class Inventory;

class Command {
public:
    virtual ~Command() = default; // Virtual destructor for Command
    virtual void execute(std::istringstream& ss,
                         std::unordered_map<int, Customer*>& customers,
                         Inventory& inventory) = 0; // Executes the command
};

#endif