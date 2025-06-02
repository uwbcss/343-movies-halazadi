#ifndef CLASSIC_H
#define CLASSIC_H

#include "Movie.h"

class Classic : public Movie {
public:
    Classic(int stock, const std::string& director, const std::string& title,
            const std::string& majorActor, int month, int year);

    std::string getKey() const override;
    void printInfo() const override;

private:
    std::string majorActor;
    int releaseMonth;
};

#endif
