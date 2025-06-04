#ifndef STORE_H
#define STORE_H

#include "Command.h"
#include "Customer.h"
#include "Inventory.h"
#include <string>
#include <unordered_map>
#include <vector>

class Store {
public:
    Store(); // Constructor
    ~Store(); // Destructor

    void loadCustomers(const std::string& filename); // Loads customer data from file
    void loadInventory(const std::string& filename); // Loads movie data from file
    void processCommands(const std::string& filename); // Executes all commands from file

private:
    std::unordered_map<int, Customer*> customers; // Customer list
    Inventory* inventory; // Pointer to inventory system

    void processCommandLine(const std::string& line); // Parses and executes a single command
    Customer* getCustomer(int id) const; // Returns customer object by ID
};

#endif
