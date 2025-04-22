#include "Shape.h"
#include <iostream>

Shape::Shape(const std::string & name, const std::string & type) : _name(name), _type(type)
{}

void Shape::printDetails() const
{
	std::cout << _type.c_str() << "\t" << _name.c_str() << "\t" << getArea() << "\t" << getPerimeter() << std::endl;
}


std::string Shape::getType() const
{ 
	return _type; 
}

std::string Shape::getName() const
{ 
	return _name; 
}