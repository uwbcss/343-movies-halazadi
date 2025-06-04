#include "MediaType.h"

// Constructor for MediaType
MediaType::MediaType(char code) : code(code) {}

// Returns the media type code
char MediaType::getCode() const { return code; }

// Returns the name of the media type based on code
std::string MediaType::getName() const {
  switch (code) {
  case 'D':
    return "DVD";
  default:
    return "Unknown";
  }
}