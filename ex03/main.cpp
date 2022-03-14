#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "Point.hpp"

using std::cout;

bool bsp(Point const a, Point const b, Point const c, Point const point);

static std::string boolToString(bool value) {
  const std::string color = value ? "\e[0;32m" : "\e[0;31m";
  const std::string boolStr = value ? "true" : "false";
  const std::string end = "\e[0m";

  return color + boolStr + end;
}

static bool isTriangle(Point a, Point b, Point c) {
  const float x1 = a.getX().toFloat(), x2 = b.getX().toFloat(),
              x3 = c.getX().toFloat();
  const float y1 = a.getY().toFloat(), y2 = b.getY().toFloat(),
              y3 = c.getY().toFloat();

  return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) != 0;
}

static void checkBSP(void) {
  Point a, b, c;
  Point point = randomPoint();
  do {
    a = randomPoint();
    b = randomPoint();
    c = randomPoint();
    cout << "a" << a << " b" << b << " c" << c << "\n";
  } while (not isTriangle(a, b, c));

  // createTriangle(triangle);

  cout << "a" << a << " b" << b << " c" << c << "\n";
  cout << "point" << point << "\n";
  cout << "point in triangle: " << boolToString(bsp(a, b, c, point)) << "\n";
}

int main(void) {
  srand(6);
  for (int i = 0; i < 10; i++)
    checkBSP();
  return 0;
}