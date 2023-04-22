#include "Point.hpp"

Vec operator-(Point const &a, Point const &b) {
  return Vec(a.getX().toFloat() - b.getX().toFloat(),
             a.getY().toFloat() - b.getY().toFloat());
}

Vec operator*(Vec const &a, Vec const &b) {
  return Vec(a.getX().toFloat() * b.getX().toFloat(),
             a.getY().toFloat() * b.getY().toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Vec ab(b - a);
  Vec ac(c - a);
  Vec ap(point - a);

  Vec u = ab * ap;
  Vec v = ac * ap;

  float ratio = u.getX().toFloat() / ab.getX().toFloat() +
                v.getX().toFloat() / ac.getX().toFloat();

  if (ratio > 1 || ratio < 0)
    return false;
  return true;
}