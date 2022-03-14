#include <iomanip>
#include <iostream>
#include "Fixed.hpp"

int main(void) {
  {
    std::cout << "<<<subject test>>>\n";
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << "\n";
    std::cout << ++a << "\n";
    std::cout << a << "\n";
    std::cout << a++ << "\n";
    std::cout << a << "\n";
    std::cout << b << "\n";

    std::cout << Fixed::max(a, b) << "\n";
  }
  {
    std::cout << "<<<custom test>>>\n";
    std::cout << "[test + - * /]\n";
    Fixed a(1), b(2), same(1);

    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << b << " = " << a * b << "\n";
    std::cout << a << " / " << b << " = " << a / b << "\n";

    std::cout << "[test > < >= <= == != >]\n";
    std::cout << a << " > " << b << " = " << std::boolalpha << (a > b) << "\n";
    std::cout << a << " < " << b << " = " << std::boolalpha << (a < b) << "\n";
    std::cout << a << " >= " << b << " = " << std::boolalpha << (a >= b)
              << "\n";
    std::cout << a << " <= " << b << " = " << std::boolalpha << (a <= b)
              << "\n";
    std::cout << a << " == " << b << " = " << std::boolalpha << (a == b)
              << "\n";
    std::cout << a << " != " << b << " = " << std::boolalpha << (a != b)
              << "\n";
    std::cout << a << " == " << same << " = " << std::boolalpha << (a == same)
              << "\n";
  }
  return 0;
}