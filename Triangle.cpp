#include "Triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const std::string& type, const std::string& name)
	: Polygon(type, name)
{
	// Meaning the points are making a line.
	if ((a.getX() == b.getX() && b.getX() == c.getX()) || (a.getY() == b.getY() && b.getY() == c.getY()))
	{
		throw std::exception("The points entered create a line.");
	}
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}

Triangle::~Triangle() {}

double Triangle::getArea() const
{
	/*
	       |     Ax(By-Cy) + Bx(Cy-Ay) + Cx(Ay-By)     |
	area = |-------------------------------------------|
	       |                    2                      |
	*/
	double sum = 0;
	sum += _points[0].getX() * (_points[1].getY() - _points[2].getY());
	sum += _points[1].getX() * (_points[2].getY() - _points[0].getY());
	sum += _points[2].getX() * (_points[0].getY() - _points[1].getY());
	return abs(sum / 2);
}

void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
