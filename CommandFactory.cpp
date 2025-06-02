#include "CommandFactory.h"

std::unordered_map<char, std::function<Command *()>> &
CommandFactory::getRegistry() {
  static std::unordered_map<char, std::function<Command *()>> registry;
  return registry;
}

void CommandFactory::registerCommand(char code,
                                     std::function<Command *()> ctor) {
  getRegistry()[code] = ctor;
}

Command *CommandFactory::create(char code) {
  auto it = getRegistry().find(code);
  return it != getRegistry().end() ? it->second() : nullptr;
}
