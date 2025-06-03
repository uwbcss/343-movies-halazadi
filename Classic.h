#ifndef CLASSIC_H
#define CLASSIC_H

#include "Inventory.h"
#include "Movie.h"
#include <string>

class Classic : public Movie {
public:
    Classic(int stock, const std::string &director, const std::string &title,
            const std::string &majorActor, int month, int year);

    std::string getKey() const override;
    void printInfo() const override;

    // Do NOT use override — this method does not exist in base class
   // static void printInventory(const Inventory &inventory);


    int getMonth() const;
    std::string getMajorActor() const;

private:
    std::string majorActor;
    int releaseMonth;
};

#endif
