#include "Point.hpp"

Vec operator-(Point const &a, Point const &b) {
  return Vec(a.getX().toFloat() - b.getX().toFloat(),
             a.getY().toFloat() - b.getY().toFloat());
}

float cross(Vec const &a, Vec const &b) {
  return a.getX().toFloat() * b.getY().toFloat() -
         a.getY().toFloat() * b.getX().toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Vec ab = b - a;
  Vec ap = point - a;

  Vec bc = c - b;
  Vec bp = point - b;

  Vec ca = a - c;
  Vec cp = point - c;

  float d1 = cross(ab, ap);
  float d2 = cross(bc, bp);
  float d3 = cross(ca, cp);

  return (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}