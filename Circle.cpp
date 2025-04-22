#include "Circle.h"

Circle::Circle(const Point & center, double radius, const std::string & type, const std::string & name)
	: Shape(name, type), _center(center), _radius(radius) 
{}

Circle::~Circle() {}

const Point& Circle::getCenter() const 
{
	return _center;
}

double Circle::getRadius() const
{
	return _radius;
}

double Circle::getArea() const
{
	return _radius * _radius * PI;
}

double Circle::getPerimeter() const
{
	return 2 * PI * _radius;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(_center, _radius);
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(_center, _radius);
}

void Circle::move(const Point& other)
{
	_center+= other;
}
