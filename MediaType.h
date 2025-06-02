#ifndef MEDIATYPE_H
#define MEDIATYPE_H

#include <string>

class MediaType {
public:
    MediaType(char code);
    char getCode() const;
    std::string getName() const;

private:
    char code; // e.g. 'D' for DVD
};

#endif
