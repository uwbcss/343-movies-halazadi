#ifndef MEDIATYPE_H
#define MEDIATYPE_H

#include <string>

class MediaType {
public:
    explicit MediaType(char code);  // Marked explicit to avoid implicit conversion
    char getCode() const;
    std::string getName() const;

private:
    char code; // e.g. 'D' for DVD
};

#endif
