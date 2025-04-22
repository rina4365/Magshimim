#pragma once

#include "Shape.h"
#include "Point.h"
#define PI 3.14

class Circle // Complete the line
{
public:
	Circle(const Point& center, double radius, const std::string& type, const std::string& name);
	~Circle();

	// ***************
	// Youre code here
	// ***************

private:
	Point _center;
	double _radius;
};