#include <iomanip>
#include <iostream>
#include "Fixed.hpp"
#include "test.hpp"

void testMandatory() {
  test::header("Mandatory");
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

void testEx01() {
  test::header("Tests from EX01");
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

void testOperator() {
  test::header("Operators");
  {
    Fixed a(5), b(2);
    test::subject("+ - * /");
    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << b << " = " << a * b << "\n";
    std::cout << a << " / " << b << " = " << a / b << "\n";
    test::subject("> < >= <= == !=");
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
    TEST_EXPECT(Fixed(4) + Fixed(11) == Fixed(15));
  }
}

void testMinMax() {
  test::header("Min and Max");
  {
    test::subject("Int Min");
    Fixed a(0.1f), b(0.2f);
    TEST_LOG(a);
    TEST_LOG(b);
    TEST_EXPECT(Fixed::min(a, b) == a);
  }
  {
    test::subject("Int Max");
    Fixed a(0.1f), b(0.2f);
    TEST_LOG(a);
    TEST_LOG(b);
    TEST_EXPECT(Fixed::max(a, b) == b);
  }
  {
    test::subject("Int same");
    Fixed a(0.1f), b(0.1f);
    TEST_LOG(a);
    TEST_LOG(b);
    TEST_EXPECT(Fixed::min(a, b) == a);
    TEST_EXPECT(Fixed::max(a, b) == b);
  }
  {
    test::subject("Float Min");
    Fixed a(0.1f), b(0.2f);
    TEST_LOG(a);
    TEST_LOG(b);
    TEST_EXPECT(Fixed::min(a, b) == a);
  }
  {
    test::subject("Float Max");
    Fixed a(0.1f), b(0.2f);
    TEST_LOG(a);
    TEST_LOG(b);
    TEST_EXPECT(Fixed::max(a, b) == b);
  }
  {
    test::subject("Float same");
    Fixed a(0.1f), b(0.1f);
    TEST_LOG(a);
    TEST_LOG(b);
    TEST_EXPECT(Fixed::min(a, b) == a);
    TEST_EXPECT(Fixed::max(a, b) == b);
  }
}

void testPrePostAddMinus() {
  test::header("Pre and Post Add and Minus");
  {
    test::subject("Pre Add");
    Fixed a(0);
    TEST_LOG(a);
    TEST_LOG(++a);
    TEST_LOG(a);
  }
  {
    test::subject("Post Add");
    Fixed a(0);
    TEST_LOG(a++);
    TEST_LOG(a);
  }
  {
    test::subject("Pre Minus");
    Fixed a(0);
    TEST_LOG(a);
    TEST_LOG(--a);
    TEST_LOG(a);
  }
  {
    test::subject("Post Minus");
    Fixed a(0);
    TEST_LOG(a--);
    TEST_LOG(a);
  }
}

int main(void) {
  testEx00();
  testEx01();
  testMandatory();
  testOperator();
  testMinMax();
  testPrePostAddMinus();
  return 0;
}
