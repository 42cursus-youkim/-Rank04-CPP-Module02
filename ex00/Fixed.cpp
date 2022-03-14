#include "Fixed.hpp"
#include <string>

// Constructors
Fixed::Fixed() {
  _rawBits = 0;
  announce("Default Constructor");
}

Fixed::Fixed(const Fixed& other) {
  announce("Copy Constructor");
  _rawBits = other.getRawBits();
}

// Destructor
Fixed::~Fixed() {
  announce("Destructor", red);
}

// Operators
Fixed& Fixed::operator=(const Fixed& other) {
  announce("Assignation operator");
  _rawBits = other.getRawBits();
  return *this;
}

// Getters / Setters
int Fixed::getRawBits() const {
  announce("getRawBits Member Function", green);
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  announce("setRawBits Member Function", green);
  _rawBits = raw;
}

// Utils
void Fixed::announce(const std::string& str, color col) const {
  const std::string colors[] = {"\e[0;31m", "\e[0;32m", "\e[0;33m"};
  const std::string end = "\e[0m";
  std::cout << colors[col] << str << " called" << end << std::endl;
}