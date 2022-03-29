#include <iostream>
#include "Fixed.hpp"
#include "test.hpp"

void testDefault() {
  test::header("Mandatory");
  Fixed a;
  Fixed b(a);
  Fixed c;

  c = b;

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
}

void testCustom() {
  test::header("Custom");
  {
    test::subject("Default Constructor is 0");
    TEST_EXPECT(Fixed().getRawBits(), 0);
  }
  {
    test::subject("Copy Constructor Works");
    Fixed a;
    a.setRawBits(42);
    Fixed b(a);
    TEST_EXPECT(b.getRawBits(), a.getRawBits());
  }
}

int main(void) {
  testDefault();
  testCustom();
  return 0;
}