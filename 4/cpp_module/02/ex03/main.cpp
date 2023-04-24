#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void) {

  Point a(0, 0);
  Point b(1, 0);
  Point c(0, 1);
  // Point point(0.2, 0.2);
  Point point(1, 1);
  // Point point(0, 0);

  bool result = bsp(a, b, c, point);
  if (result)
    std::cout << "Point is in triangle" << std::endl;
  else
    std::cout << "Point is not in triangle" << std::endl;

  return 0;
}