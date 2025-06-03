#ifndef INVENTORY_H
#define INVENTORY_H

#include "Movie.h"
#include <map>
#include <string>
#include <vector>

class Inventory {
public:

std::vector<Movie*> getAllMoviesOfGenre(char genre) const;

    Inventory();
    ~Inventory();

    void loadFromFile(const std::string& filename);
    void printInventory() const;

    Movie* getMovie(const std::string& key) const;
    void addMovie(Movie* movie);


private:
    std::map<char, std::map<std::string, Movie*>> moviesByGenre;
};

#endif
