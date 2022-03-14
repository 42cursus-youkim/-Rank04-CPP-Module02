#include "Point.hpp"

inline float sign(Point p1, Point p2, Point p3) {
  const float p1x = p1.getX().toFloat();
  const float p2x = p2.getX().toFloat();
  const float p3x = p3.getX().toFloat();
  const float p1y = p1.getY().toFloat();
  const float p2y = p2.getY().toFloat();
  const float p3y = p3.getY().toFloat();

  return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

// Check if a point is inside a triangle using bsp algorithm
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  const float d1 = sign(point, a, b);
  const float d2 = sign(point, b, c);
  const float d3 = sign(point, c, a);

  const bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  const bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

  return not(has_neg and has_pos);
}