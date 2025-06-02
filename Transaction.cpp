#include "Transaction.h"

Transaction::Transaction(char type, const std::string &movieInfo)
    : actionType(type), movieInfo(movieInfo) {}

std::string Transaction::toString() const {
  std::string action = (actionType == 'B') ? "Borrowed: " : "Returned: ";
  return action + movieInfo;
}
