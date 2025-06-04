#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie {
public:
    Movie(char genre, int stock, const std::string& director, const std::string& title, int year); // Constructor for Movie
    virtual ~Movie() = default; // Virtual destructor for Movie

    char getGenre() const; // Returns the movie genre
    int getStock() const; // Returns the number of items in stock
    void increaseStock(); // Increases the stock count by one
    bool decreaseStock(); // Decreases the stock count by one if possible

    std::string getTitle() const; // Returns the movie title
    std::string getDirector() const; // Returns the movie director
    int getYear() const; // Returns the movie release year

    virtual std::string getKey() const = 0; // Returns the unique lookup key for the movie
    virtual void printInfo() const = 0; // Prints information about the movie

protected:
    char genre;
    int stock;
    std::string director;
    std::string title;
    int year;
};

#endif