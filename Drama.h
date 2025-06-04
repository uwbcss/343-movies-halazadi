#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"
#include <string>

class Inventory; // Forward declaration

class Drama : public Movie {
public:
    Drama(int stock, const std::string &director, const std::string &title, int year); // Drama constructor
    std::string getKey() const override; // Gets the unique key for this movie
    void printInfo() const override; // Prints info about the drama movie

    static void printInventory(const Inventory &inventory); // Prints all drama movies in inventory
};

#endif // DRAMA_H