#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Transaction;

class Customer {
public:
    Customer(int id, const std::string& first, const std::string& last);
    ~Customer();

    int getID() const;
    std::string getName() const;

    void addTransaction(const std::string& transaction);
    void printHistory() const;

private:
    int id;
    std::string firstName;
    std::string lastName;
    std::vector<std::string> history;
};

#endif
