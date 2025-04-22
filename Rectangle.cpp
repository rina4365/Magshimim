#include "Rectangle.h"
#include <exception>


myShapes::Rectangle::Rectangle(const Point& a, double length, double width, const std::string& type, const std::string& name): Polygon(type, name)
{
	// Meaning the points are making a line.
	if (width == 0 || length == 0)
	{
		throw std::exception("Length or Width can't be 0.");
	}
	_points.push_back(a);
	_points.push_back(Point(a.getX() + abs(length), a.getY() + abs(width)));
}

myShapes::Rectangle::~Rectangle()
{}

double myShapes::Rectangle::getArea() const
{
	// Get the third point so calculating the distance will be duable.
	Point thirdPoint(_points[0].getX(), _points[1].getY());
	return abs(_points[0].distance(thirdPoint) * _points[1].distance(thirdPoint));
}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[1]);
}


