#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : _rawBits(0) {
  announce("Default Constructor");
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {
  announce("Int Constructor", GRN);
}

Fixed::Fixed(const float value)
    : _rawBits(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
  announce("Float Constructor", GRN);
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

// Conversion
int Fixed::toInt() const {
  return _rawBits >> _fractionalBits;
}

float Fixed::toFloat() const {
  return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

// Getters / Setters
int Fixed::getRawBits() const {
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  _rawBits = raw;
}

// Utils
void Fixed::announce(const std::string& str, const std::string& col) const {
  std::cout << col << str << " called" << END "\n";
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}