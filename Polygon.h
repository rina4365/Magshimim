#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape// Complete the line
{
public:
	Polygon(const std::string& type, const std::string& name);

	// ***************
	// Youre code here
	// ***************

protected:
	std::vector<Point> _points;
};