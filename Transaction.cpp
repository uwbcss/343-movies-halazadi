#include "Transaction.h"

// Constructor that sets the transaction type and movie info
Transaction::Transaction(char type, const std::string &movieInfo)
    : actionType(type), movieInfo(movieInfo) {}

// Converts the transaction to a readable string
std::string Transaction::toString() const {
  std::string action = (actionType == 'B') ? "Borrowed: " : "Returned: ";
  return action + movieInfo;
}
