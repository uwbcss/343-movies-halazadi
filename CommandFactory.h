#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <functional>
#include <unordered_map>

class CommandFactory {
public:
    static Command* create(char code); // Creates a command object based on code
    static void registerCommand(char code, std::function<Command*()> ctor); // Registers a command with code

private:
    static std::unordered_map<char, std::function<Command*()>>& getRegistry(); // Gets the command registry
};

#endif