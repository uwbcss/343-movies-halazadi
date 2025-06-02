#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"

class Comedy : public Movie {
public:
    Comedy(int stock, const std::string& director, const std::string& title, int year);

    std::string getKey() const override;
    void printInfo() const override;
};

#endif
