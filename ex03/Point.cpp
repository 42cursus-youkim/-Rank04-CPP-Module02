#include "Point.hpp"
#include <stdlib.h>

// Constructors
Point::Point() : _x(0), _y(0) {}
Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}
Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}

// Destructor
Point::~Point() {}

// Operators
#include <iostream>
Point& Point::operator=(const Point& assign) {
  if (this != &assign) {
    const_cast<Fixed&>(_x) = assign.getX();
    const_cast<Fixed&>(_y) = assign.getY();
  }
  return *this;
}

bool Point::operator==(const Point& other) const {
  return (_x == other.getX() && _y == other.getY());
}

// Getters / Setters
const Fixed Point::getX() const {
  return _x;
}

const Fixed Point::getY() const {
  return _y;
}

Point randomPoint() {
  const int x = rand() % 5, y = rand() % 5;
  return Point(Fixed(x), Fixed(y));
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
  return os << "(" << point.getX() << ", " << point.getY() << ")";
}

// Getters / Setters
