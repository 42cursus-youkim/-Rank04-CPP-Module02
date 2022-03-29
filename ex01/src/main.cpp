#include <iostream>
#include "Fixed.hpp"
#include "test.hpp"

void testMandatory() {
  test::header("Mandatory");
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void testEx00() {
  test::header("Tests from EX00");
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

void testConversion() {
  test::header("Conversions");
  {
    test::subject("Integer value converion is Correct");
    int val = 42;
    TEST_LOG(val);
    Fixed a(val);
    TEST_EXPECT(a.getRawBits() == (val << 8));
    TEST_EXPECT(a.toInt() == val);
  }
  {
    test::subject("Float -> Int");
    float val = 42.42f;
    TEST_LOG(val);
    Fixed a(val);
    TEST_EXPECT(a.toInt() == 42);
  }
  {
    test::subject("Int -> Float");
    int val = 42;
    TEST_LOG(val);
    Fixed a(val);
    TEST_EXPECT(a.toFloat() == 42.0f);
  }
}

int main(void) {
  testMandatory();
  testEx00();
  testConversion();
  return 0;
}