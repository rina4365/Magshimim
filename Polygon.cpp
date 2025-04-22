#include "Polygon.h"

Polygon::Polygon(const std::string & type, const std::string & name): Shape(name, type)
{}

Polygon::~Polygon()
{}

void Polygon::move(const Point& other) 
{
	for (int i = 0; i < _points.size(); i++)
	{
		_points[i] += other;
	}
}

double Polygon::getPerimeter() const
{
	double sum = 0;

	// Calculate all the distances on the current polygon.
	for (int i = 0; i < _points.size() - 1; i++)
	{
		sum += _points[i].distance(_points[i + 1]);
	}

	sum += _points[_points.size() - 1].distance(_points[0]);

	return sum;
}

