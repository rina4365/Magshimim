#include "Point.h"
#include <math.h>

Point::Point(double x, double y)
{
	_x = x;
	_y = y;
}

Point::Point(const Point& other)
{
	_x = other.getX();
	_y = other.getY();
}

Point::~Point()
{}

Point Point::operator+(const Point& other) const
{
	Point point(_x + other.getX(), _y + other.getY());
	return point;
}

Point& Point::operator+=(const Point & other)
{
	_x += other.getX();
	_y += other.getY();

	return *this;
}

double Point::getX() const
{
	return _x;
}

double Point::getY() const
{
	return _y;
}

double Point::distance(const Point& other) const
{	
	// Calculate correct distance.
	return sqrt( pow(_x - other.getX(), 2) + pow(_y - other.getY(), 2));
}
