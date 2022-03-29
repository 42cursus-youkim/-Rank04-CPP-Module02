#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
#include "color.hpp"

using std::cout;

namespace test {

template <typename T>
void header(T const& t) {
  cout << "[[" << t << ":\n";
}

template <typename T>
void logln(T value) {
  cout << value << "\n";
}

}  // namespace test
#endif  // __TEST_H__