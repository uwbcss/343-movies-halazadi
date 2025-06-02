#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(char type, const std::string& movieInfo);

    std::string toString() const;

private:
    char actionType;  // 'B' or 'R'
    std::string movieInfo;
};

#endif
