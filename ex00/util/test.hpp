#ifndef __TEST_H__
#define __TEST_H__

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "color.hpp"

using std::cout;
using std::string;

// Macros
#define TEST_EXPECT(expected, actual) \
  test::expect(#expected " == " #actual, expected, actual)

#define TEST_LOG(x) test::log(#x, x)

namespace test {

template <typename T>
void header(T const& t) {
  cout << BHYEL << string(80, '-') << "\n";
  cout << "[[[ Testing " BBLU << t << BHYEL " ]]]\n" END;
}

template <typename T>
void subject(T const& t) {
  cout << MAG "\n[ case " BCYN << t << MAG " ]\n" END;
}

template <typename T>
void log(const string& str, T value) {
  cout << BLU << str << HYEL ": " BCYN << value << "\n";
}

template <typename T>
void expect(const string& name, T const& expected, T const& actual) {
  cout << BLU << name << HYEL ": ";
  if (expected == actual) {
    cout << BGRN << "OK\n" END;
  } else {
    cout << BRED << "KO\n";
    cout << " expected: " << expected << " actual: " << actual << END "\n";
    std::exit(EXIT_FAILURE);
  }
}
}  // namespace test

#endif  // __TEST_H__