#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <unordered_set>
#include <vector>

class Transaction;

class Customer {
public:
    Customer(int id, const std::string& first, const std::string& last); // Constructor for Customer
    ~Customer(); // Destructor for Customer

    int getID() const; // Returns the customer ID
    std::string getName() const; // Returns the full customer name

    void addTransaction(const std::string& transaction); // Adds a transaction to the customer's history
    void printHistory() const; // Prints the customer's transaction history

    // New methods for borrow/return tracking
    void addBorrowedMovie(const std::string& movieKey); // Adds a movie to the borrowed set
    bool hasBorrowedMovie(const std::string& movieKey) const; // Checks if a movie is currently borrowed
    void removeBorrowedMovie(const std::string& movieKey); // Removes a movie from the borrowed set

private:
    int id;
    std::string firstName;
    std::string lastName;
    std::vector<std::string> history;
    std::unordered_set<std::string> borrowedMovies; // NEW
};

#endif