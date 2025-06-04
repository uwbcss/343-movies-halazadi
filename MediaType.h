#ifndef MEDIATYPE_H
#define MEDIATYPE_H

#include <string>

class MediaType {
public:
    explicit MediaType(char code);  // Constructor for MediaType, marked explicit to avoid implicit conversion
    char getCode() const; // Returns the media type code
    std::string getName() const; // Returns the name of the media type

private:
    char code; // e.g. 'D' for DVD
};

#endif