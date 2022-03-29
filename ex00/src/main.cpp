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
    test::subject("Default Constructor value is 0");
    TEST_EXPECT(Fixed().getRawBits() == 0);
  }
  {
    test::subject("Copy Constructor Works (is deep copied)");
    Fixed* a = new Fixed;
    a->setRawBits(42);
    int temp_a_rawbits = a->getRawBits();
    Fixed b(*a);  // construct a new Fixed with the value of a
    delete a;     // b should have been deep copied
    TEST_EXPECT(b.getRawBits() == temp_a_rawbits);
  }
  {
    test::subject("Copy Assignment Works");
    Fixed a;
    a.setRawBits(42);
    Fixed b;
    b = a;
    TEST_EXPECT(b.getRawBits() == a.getRawBits());
  }
  {
    test::subject("Getter and Setter Works");
    Fixed a;
    a.setRawBits(42);
    TEST_EXPECT(a.getRawBits() == 42);
    a.setRawBits(12);
    TEST_EXPECT(a.getRawBits() == 12);
  }
}

int main(void) {
  testDefault();
  testCustom();
  return 0;
}