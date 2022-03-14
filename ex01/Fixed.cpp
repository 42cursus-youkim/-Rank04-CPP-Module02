#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : _rawBits(0) {
  announce("Default Constructor");
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {
  announce("Int Constructor", green);
  ;
}

Fixed::Fixed(const float value)
    : _rawBits(roundf(value * (1 << _fractionalBits))) {
  announce("Float Constructor", green);
}

Fixed::Fixed(const Fixed& other) : _rawBits(other.getRawBits()) {
  announce("Copy Constructor");
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

// Conversion
int Fixed::toInt() const {
  return _rawBits >> _fractionalBits;
}

float Fixed::toFloat() const {
  return (float)_rawBits / (1 << _fractionalBits);
}

// Getters / Setters
int Fixed::getRawBits() const {
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  _rawBits = raw;
}

// Utils
void Fixed::announce(const std::string& str, color col) const {
  const std::string colors[] = {"\e[0;31m", "\e[0;32m", "\e[0;33m"};
  const std::string end = "\e[0m";
  std::cout << colors[col] << str << " called" << end << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}