#include "Point.hpp"

Point::Point() : x(0) , y(0) {}

Point::Point( const float x, const float y ) : x(x), y(y) {}

Point::Point( const Point& copy ) : x(copy.getX()), y(copy.getY()) {}

Point::~Point(void) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

float Point::getX(void) const
{
    return (x.toFloat());
}

float Point::getY(void) const
{
    return (y.toFloat());
}
