#pragma once
#include "Polygon.h"

class Arrow: public Shape
{
public:
	Arrow(const Point& a, const Point& b, const std::string& type, const std::string& name);
	~Arrow();

	// ***************
	// Youre code here
	// ***************

private:
	std::vector<Point> _points;
};

