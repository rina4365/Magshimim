#include "Arrow.h"


Arrow::Arrow(const Point& a, const Point& b, const std::string& type, const std::string& name)
	: Shape(type, name)
{
	_points.push_back(a);
	_points.push_back(b);
}


Arrow::~Arrow()
{
}

void Arrow::move(const Point & other)
{
	Point newPoint(other.getX(), other.getY() * -1);
	
	for (int i = 0; i < _points.size(); i++)
	{
		_points[i] += newPoint;
	}
}

double Arrow::getPerimeter() const
{
	return _points[0].distance(_points[1]);
}

double Arrow::getArea() const
{
	return 0.0;
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_points[0], _points[1]);
}

void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_points[0], _points[1]);
}


