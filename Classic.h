#ifndef CLASSIC_H
#define CLASSIC_H

#include "Inventory.h"
#include "Movie.h"
#include <string>

class Classic : public Movie {
public:
    Classic(int stock, const std::string &director, const std::string &title,
            const std::string &majorActor, int month, int year); // Classic constructor

    std::string getKey() const override; // Gets the unique key for this movie
    void printInfo() const override; // Prints info about the classic movie

    int getMonth() const; // Gets the release month
    std::string getMajorActor() const; // Gets the major actor

private:
    std::string majorActor;
    int releaseMonth;
};

#endif