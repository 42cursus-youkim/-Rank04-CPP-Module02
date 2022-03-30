#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

const int MAX_RANDOM_POINT_SIZE = 6;

class Point {
 public:
  // Constructors
  Point();
  Point(const Point& copy);
  Point(const float x, const float y);

  // Destructor
  ~Point();

  // Operators
  Point& operator=(const Point& assign);
  bool operator==(const Point& other) const;

  // Getters / Setters
  const Fixed getX() const;
  const Fixed getY() const;

 private:
  const Fixed _x;
  const Fixed _y;
};

Point randomPoint();

std::ostream& operator<<(std::ostream& os, const Point& point);

#endif