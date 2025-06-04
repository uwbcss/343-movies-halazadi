#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(char type, const std::string& movieInfo); // Constructor

    std::string toString() const; // Returns a string description of the transaction

private:
    char actionType;  // 'B' for borrow or 'R' for return
    std::string movieInfo; // Description of the movie involved
};

#endif
