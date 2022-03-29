#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {}

Fixed::Fixed(const float value)
    : _rawBits(roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : _rawBits(other.getRawBits()) {}

// Destructor
Fixed::~Fixed() {}

// Operators
Fixed& Fixed::operator=(const Fixed& other) {
  _rawBits = other.getRawBits();
  return *this;
}

// >, <, >=, <=, ==, !=
bool Fixed::operator>(const Fixed& other) const {
  return _rawBits > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
  return _rawBits < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
  return _rawBits >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
  return _rawBits <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
  return _rawBits == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
  return _rawBits != other.getRawBits();
}

// +, -, *, /
Fixed Fixed::operator+(const Fixed& other) const {
  Fixed result;

  result.setRawBits(_rawBits + other.getRawBits());
  return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
  Fixed result;

  result.setRawBits(_rawBits - other.getRawBits());
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
  Fixed result;

  result.setRawBits((_rawBits * other.getRawBits()) >> _fractionalBits);
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
  Fixed result;

  result.setRawBits((_rawBits << _fractionalBits) / other.getRawBits());
  return result;
}

// ++, --
Fixed& Fixed::operator++() {
  _rawBits++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++(*this);
  return temp;
}

Fixed& Fixed::operator--() {
  _rawBits--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --(*this);
  return temp;
}

// min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return a < b ? a : b;
};

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return a > b ? a : b;
};

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
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}