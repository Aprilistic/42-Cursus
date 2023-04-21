#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

#define Vec Point

class Point{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		Point &operator=(const Point &point);
		~Point();

		Fixed const &getX() const;
		Fixed const &getY() const;
};

#endif // POINT_HPP_