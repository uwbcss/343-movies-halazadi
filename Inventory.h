#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>
#include <vector>
#include "Movie.h"

class Inventory {
public:
    Inventory();
    ~Inventory();

    void loadFromFile(const std::string& filename);
    void printInventory() const;

    Movie* getMovie(const std::string& key) const;
    void addMovie(Movie* movie);

private:
    std::map<std::string, std::vector<Movie*>> moviesByGenre;
};

#endif
