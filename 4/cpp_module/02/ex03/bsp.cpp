#include "Point.hpp"

Vec operator-(Point const &a, Point const &b)
{
	return Vec(a.getX() - b.getX(), a.getY() - b.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Vec ab(b - a);
	Vec ac(c - a);
	Vec ap(point - a);

	
}