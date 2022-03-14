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
    Fixed a(0.1f), b(0.2f);

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
    // check that a(0.1f) + b(0.2f) = result(0.3f)
    Fixed same(0.1f), result(0.3f);
    std::cout << a << " + " << b << " == " << result << std::boolalpha
              << (a + b == result) << "\n";
  }
  return 0;
}