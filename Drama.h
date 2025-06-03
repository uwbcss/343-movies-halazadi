#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"
#include <string>

class Inventory; // Forward declaration

class Drama : public Movie {
public:
    Drama(int stock, const std::string &director, const std::string &title, int year);
    std::string getKey() const override;
    void printInfo() const override;

    // Static so it doesn't require a specific Drama instance
    static void printInventory(const Inventory &inventory);
};

#endif // DRAMA_H
