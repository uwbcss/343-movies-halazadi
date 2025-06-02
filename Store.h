#ifndef STORE_H
#define STORE_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Customer.h"
#include "Inventory.h"
#include "Command.h"

class Store {
public:
    Store();
    ~Store();

    void loadCustomers(const std::string& filename);
    void loadInventory(const std::string& filename);
    void processCommands(const std::string& filename);

private:
    std::unordered_map<int, Customer*> customers;
    Inventory* inventory;

    void processCommandLine(const std::string& line);
    Customer* getCustomer(int id) const;
};

#endif
