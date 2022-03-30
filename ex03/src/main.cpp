#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include "Point.hpp"
#include "color.hpp"
#include "test.hpp"

using std::cout;

bool bsp(Point const a, Point const b, Point const c, Point const point);

bool isTriangle(Point a, Point b, Point c) {
  const float x1 = a.getX().toFloat(), x2 = b.getX().toFloat(),
              x3 = c.getX().toFloat();
  const float y1 = a.getY().toFloat(), y2 = b.getY().toFloat(),
              y3 = c.getY().toFloat();

  return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) != 0;
}

void represent(Point a, Point b, Point c, Point point) {
  char board[MAX_RANDOM_POINT_SIZE][MAX_RANDOM_POINT_SIZE];

  for (int i = 0; i < MAX_RANDOM_POINT_SIZE; i++)
    for (int j = 0; j < MAX_RANDOM_POINT_SIZE; j++)
      board[i][j] = '.';

  board[a.getX().toInt()][a.getY().toInt()] = 'A';
  board[b.getX().toInt()][b.getY().toInt()] = 'B';
  board[c.getX().toInt()][c.getY().toInt()] = 'C';
  board[point.getX().toInt()][point.getY().toInt()] = 'P';

  for (int i = 0; i < MAX_RANDOM_POINT_SIZE; i++) {
    for (int j = 0; j < MAX_RANDOM_POINT_SIZE; j++) {
      char c = board[i][j];
      if (c == 'P')
        cout << GRN << c << END;
      else if (c != '.')
        cout << RED << c << END;
      else
        cout << c;
    }
    cout << "\n";
  }
}

std::string boolToString(bool value) {
  const std::string color = value ? GRN : RED;
  const std::string boolStr = value ? "true" : "false";

  return color + boolStr + END;
}

bool checkBSP(Point a, Point b, Point c, Point point) {
  bool result = bsp(a, b, c, point);
  represent(a, b, c, point);
  TEST_LOG(a);
  TEST_LOG(b);
  TEST_LOG(c);
  TEST_LOG(point);
  cout << "\nin triangle? " << boolToString(result) << "\n";
  return result;
}

bool checkBSPauto() {
  Point a, b, c;
  Point point = randomPoint();
  do {
    a = randomPoint();
    b = randomPoint();
    c = randomPoint();
  } while (not isTriangle(a, b, c) or a == point or b == point or c == point);
  return checkBSP(a, b, c, point);
}

void testCases(int iteration) {
  srand(13929);
  for (int i = 0; i < iteration; i++) {
    test::subject(i + 1);
    checkBSPauto();
  }
}

void testEdge() {
  test::header("On Edge");
  Point a(0, 0), b(0, 4), c(4, 0), point(2, 0);
  checkBSP(a, b, c, point);
}

void testVertex() {
  test::header("On Vertex");
  Point a(0, 0), b(0, 4), c(4, 0);
  test::subject("a == point");
  checkBSP(a, b, c, a);
  test::subject("b == point");
  checkBSP(a, b, c, b);
  test::subject("c == point");
  checkBSP(a, b, c, c);
}

int main(void) {
  testCases(10);
  testVertex();
  testEdge();
  return 0;
}