#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "Movie.h"
#include <string>

class MovieFactory {
public:
    static Movie* createMovie(const std::string& line); // Creates a Movie object from a line of text
};

#endif