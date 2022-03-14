#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
 private:
  int _rawBits;
  static const int _fractionalBits = 8;

 public:
  // Constructors
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& other);

  // Destructor
  ~Fixed();

  // Operators
  Fixed& operator=(const Fixed& other);

  // >, <, >=, <=, ==, !=
  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  // +, -, *, /
  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  // ++, --
  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  // min/max
  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  // Conversion
  int toInt() const;
  float toFloat() const;

  // Getters / Setters
  int getRawBits() const;
  void setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif