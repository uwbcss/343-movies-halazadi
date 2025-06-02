#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Command.h"
#include <unordered_map>
#include <functional>

class CommandFactory {
public:
    static Command* create(char code);
    static void registerCommand(char code, std::function<Command*()> ctor);

private:
    static std::unordered_map<char, std::function<Command*()>>& getRegistry();
};

#endif
