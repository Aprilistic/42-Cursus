#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {}

Point &Point::operator=(const Point &point){
	if (this != &point){
		const_cast<Fixed&>(_x) = point.getX();
		const_cast<Fixed&>(_y) = point.getY();
	}
	return *this;
}

Point::~Point() {}

Fixed const &Point::getX() const{
	return _x;
}

Fixed const &Point::getY() const{
	return _y;
}
