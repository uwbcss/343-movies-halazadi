#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <unordered_set>
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

    // New methods for borrow/return tracking
    void addBorrowedMovie(const std::string& movieKey);
    bool hasBorrowedMovie(const std::string& movieKey) const;
    void removeBorrowedMovie(const std::string& movieKey);

private:
    int id;
    std::string firstName;
    std::string lastName;
    std::vector<std::string> history;
    std::unordered_set<std::string> borrowedMovies; // NEW
};

#endif
