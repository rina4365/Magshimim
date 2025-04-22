#pragma once
#include "Point.h"
#include "Canvas.h"
#include <string>

class Shape 
{
public:
	Shape(const std::string& name, const std::string& type);

	void printDetails() const;
	std::string getType() const;
	std::string getName() const


	// ***************
	// Youre code here
	// ***************

private:
	std::string _name;
	std::string _type;
};