#ifndef COMEDY_H
#define COMEDY_H

#include "Inventory.h"
#include "Movie.h"

class Comedy : public Movie {
public:
    Comedy(int stock, const std::string& director, const std::string& title, int year); // Comedy constructor

    std::string getKey() const override; // Gets the unique key for this movie
    void printInfo() const override; // Prints info about the comedy movie
    static void printInventory(const Inventory& inventory);  // Prints all comedy movies in inventory
};

#endif