#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie {
public:
    Movie(char genre, int stock, const std::string& director, const std::string& title, int year);
    virtual ~Movie() = default;

    char getGenre() const;
    int getStock() const;
    void increaseStock();
    bool decreaseStock();

    std::string getTitle() const;
    std::string getDirector() const;
    int getYear() const;

    virtual std::string getKey() const = 0; // unique lookup key
    virtual void printInfo() const = 0;

protected:
    char genre;
    int stock;
    std::string director;
    std::string title;
    int year;
};

#endif
