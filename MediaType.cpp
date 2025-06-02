#include "MediaType.h"

MediaType::MediaType(char code) : code(code) {}

char MediaType::getCode() const { return code; }

std::string MediaType::getName() const {
  switch (code) {
  case 'D':
    return "DVD";
  default:
    return "Unknown";
  }
}
