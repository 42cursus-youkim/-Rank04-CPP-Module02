#include "Point.hpp"

inline float sign(Point p1, Point p2, Point p3) {
  const float p1x = p1.getX().toFloat();
  const float p2x = p2.getX().toFloat();
  const float p3x = p3.getX().toFloat();
  const float p1y = p1.getY().toFloat();
  const float p2y = p2.getY().toFloat();
  const float p3y = p3.getY().toFloat();

  return ((p1x - p3x) * (p2y - p3y)) - ((p2x - p3x) * (p1y - p3y));
}

inline bool onVertex(Point const a,
                     Point const b,
                     Point const c,
                     Point const point) {
  return a == point or b == point or c == point;
}

inline float absFloat(float value) {
  return value < 0 ? -value : value;
}

inline bool onEdge(const float d1, const float d2, const float d3) {
  const float epsilon = 0.01;
  return absFloat(d1) < epsilon or absFloat(d2) < epsilon or
         absFloat(d3) < epsilon;
}

// Check if a point is inside a triangle using bsp algorithm
// if on vertex or edge, returns False.
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  if (onVertex(a, b, c, point))
    return false;

  const float d1 = sign(point, a, b);
  const float d2 = sign(point, b, c);
  const float d3 = sign(point, c, a);

  if (onEdge(d1, d2, d3))
    return false;

  const bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  const bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

  return not(has_neg and has_pos);
}