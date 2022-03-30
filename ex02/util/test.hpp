#ifndef __TEST_H__
#define __TEST_H__

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "color.hpp"

using std::cerr;
using std::cout;
using std::string;

// Macros
#define TEST_EXPECT(expr)                                                   \
  do {                                                                      \
    assert(expr);                                                           \
    cout << HMAG "{ assert " BBLU << #expr << HMAG " } " BGRN " OK!\n" END; \
  } while (0);

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
  cout << BLU << str << HYEL ": " BCYN << value << "\n" END;
}

}  // namespace test

#endif  // __TEST_H__