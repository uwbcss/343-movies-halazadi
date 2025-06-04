#ifndef INVENTORY_H
#define INVENTORY_H

#include "Movie.h"
#include <map>
#include <string>
#include <vector>

class Inventory {
public:
    std::vector<Movie*> getAllMoviesOfGenre(char genre) const; // Returns all movies of a specific genre

    Inventory(); // Constructor for Inventory
    ~Inventory(); // Destructor for Inventory

    void loadFromFile(const std::string& filename); // Loads movies from a file
    void printInventory() const; // Prints all movies in the inventory

    Movie* getMovie(const std::string& key) const; // Returns a pointer to a movie by key
    void addMovie(Movie* movie); // Adds a movie to the inventory

private:
    std::map<char, std::map<std::string, Movie*>> moviesByGenre;
};

#endif