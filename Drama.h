#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama : public Movie {
public:
    Drama(int stock, const std::string& director, const std::string& title, int year);

    std::string getKey() const override;
    void printInfo() const override;
};

#endif
