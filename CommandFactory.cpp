#include "CommandFactory.h"

std::unordered_map<char, std::function<Command *()>> &
CommandFactory::getRegistry() {
  // Returns the command registry
  static std::unordered_map<char, std::function<Command *()>> registry;
  return registry;
}

void CommandFactory::registerCommand(char code,
                                     std::function<Command *()> ctor) {
  // Registers a command with a specific code
  getRegistry()[code] = ctor;
}

Command *CommandFactory::create(char code) {
  // Creates and returns a command object for the given code
  auto it = getRegistry().find(code);
  return it != getRegistry().end() ? it->second() : nullptr;
}