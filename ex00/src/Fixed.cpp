#include "Fixed.hpp"
#include <string>

// Constructors
Fixed::Fixed() : _rawBits(0) {
  announce("Default Constructor");
}

Fixed::Fixed(const Fixed& other) : _rawBits(other.getRawBits()) {
  announce("Copy Constructor");
}

// Destructor
Fixed::~Fixed() {
  announce("Destructor", RED);
}

// Operators
Fixed& Fixed::operator=(const Fixed& other) {
  announce("Copy assignment operator");
  _rawBits = other.getRawBits();
  return *this;
}

// Getters / Setters
int Fixed::getRawBits() const {
  announce("getRawBits Member Function", GRN);
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  announce("setRawBits Member Function", GRN);
  _rawBits = raw;
}

// Utils
void Fixed::announce(const std::string& str, const std::string& col) const {
  std::cout << col << str << " called" << END "\n";
}