#include "Menu.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

Menu::Menu()
{ }

Menu::~Menu()
{ }

unsigned short Menu::displayChoicesMenu()
{
	unsigned short choice;
	do
	{
		system("cls");
		cout << "Enter " << add_shape_choice << " to add a new shape." <<
			endl << "Enter " << modify_shape_choice << " to modify or get information from a current shape." <<
			endl << "Enter " << delete_all_shapes << " to delete all of the shapes." <<
			endl << "Enter " << exit_choice << " to exit." << endl;
		cin >> choice;
	} while (choice < add_shape_choice || choice > exit_choice);
	return choice;
}

void Menu::add_shape(vector<Shape*>& shapes)
{
	auto chosen_shape = displayShapeObjectsMenu();

	switch (chosen_shape)
	{
		case circle: 
			addCircle(shapes); 
			break;
		case arrow: 
			addArrow(shapes); 
			break;
		case triangle: 
			addTriangle(shapes); 
			break;
		case rectangle: 
			addRectangle(shapes); 
			break;
	}
}

unsigned short Menu::displayShapeObjectsMenu()
{
	unsigned short choice;
	do
	{
		system("cls");
		cout << "Enter " << circle << " to add a circle." <<
			endl << "Enter " << arrow << " to add an arrow." <<
			endl << "Enter " << triangle << " to add a triangle." <<
			endl << "Enter " << rectangle << " to add a rectangle." << endl;
		cin >> choice;
	} while (choice < circle || choice > rectangle);
	return choice;
}

void Menu::addCircle(vector<Shape*>& shapes)
{
	double x, y, radius;
	string name;
	cout << "Please enter X: " << endl;
	cin >> x;
	cout << "Please enter Y: " << endl;
	cin >> y;
	cout << "Please enter radius: " << endl;
	cin >> radius;
	cout << "Please enter the name of the shape:" << endl;
	cin >> name;

	Circle* c = new Circle(Point(x, y), radius, "Circle", name);
	shapes.push_back(c);

	srand(time(NULL));
	c->draw(_canvas);
}

void Menu::addArrow(vector<Shape*>& shapes)
{
	string name;
	vector<Point> points;
	double x, y;

	for (int i = 0; i < 2; i++) {
		cout << "Enter the X of point number: " << i + 1 << endl;
		cin >> x;
		cout << "Enter the Y of point number: " << i + 1 << endl;
		cin >> y;
		points.push_back(Point(x, y));
	}


	cout << "Enter the name of the shape: " << endl;
	cin >> name;

	
	Arrow* a = new Arrow(points[0], points[1], "Arrow", name);
	shapes.push_back(a);

	srand(time(NULL));
	a->draw(_canvas);
	
}

void Menu::addTriangle(vector<Shape*>& shapes)
{
	vector<Point> points;
	string name;
	double x, y;

	for (int i = 0; i < 3; i++) {
		cout << "Enter the X of point number: " << i + 1 << endl;
		cin >> x;
		cout << "Enter the Y of point number: " << i + 1 << endl;
		cin >> y;

		points.push_back(Point(x, y));
	}
	cout << "Enter the name of the shape: " << endl;
	cin >> name;

	Triangle* t = new Triangle(points[0], points[1], points[2], "Triangle", name);
	shapes.push_back(t);

	srand(time(NULL));
	t->draw(_canvas);
}

void Menu::addRectangle(vector<Shape*>& shapes)
{
	string name;
	cout << "Enter the X of the to left corner: " << endl;
	double x, y;
	cin >> x;
	cout << "Enter the Y of the top left corner: " << endl;
	cin >> y;

	cout << "Please enter the length of the shape: " << endl;
	double length, width;
	cin >> length;
	cout << "Please enter the width of the shape: " << endl;
	cin >> width;

	cout << "Enter the name of the shape: " << endl;
	cin >> name;

	myShapes::Rectangle* r = new myShapes::Rectangle(Point(x, y), length, width, "Rectangle", name);
	shapes.push_back(r);

	srand(time(NULL));
	r->draw(_canvas);
}

void Menu::showAllShapes(vector<Shape*>& shapes)
{
	unsigned short choice;
	if (shapes.size() == 0)
		return;
	do
	{
		system("cls");
		for (int i = 0; i < shapes.size(); i++) {
			cout << "Enter " << i << " for " << shapes[i]->getName() <<
				"(" << shapes[i]->getType() << ")" << endl;
		}
		cin >> choice;
	} while (choice < 0 || choice >= shapes.size());

	showModifyShapeMenu(shapes, choice);
}

void Menu::showModifyShapeMenu(vector<Shape*>& shapes, unsigned short index)
{
	unsigned short choice;
	do
	{
		cout << "Enter " << move_shape << " to move the shape" <<
			endl << "Enter " << get_details << " to get its details." <<
			endl << "Enter " << remove_shape << " to remove the shape." << endl;
		cin >> choice;
	} while (choice < move_shape || choice > remove_shape);

	switch (choice)
	{
		case move_shape: 
			moveShapeMenu(shapes, index); 
			break;
		case get_details: 
			shapes[index]->printDetails(); 
			system("PAUSE"); 
			break;
		case remove_shape: 
			removeShape(shapes, index, true); 
			break;
	}
}

void Menu::moveShapeMenu(vector<Shape*>& shapes, unsigned short index)
{
	system("cls");
	cout << "Please enter the X moving scale: ";
	double x, y;
	cin >> x;
	cout << "Please enter the Y moving scale: ";
	cin >> y;

	removeShape(shapes, index, false);
	shapes[index]->move(Point(x, y));
	shapes[index]->draw(_canvas);
}

void Menu::removeShape(vector<Shape*>& shapes, unsigned short index, bool delete_from_shapes)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		// Print everything back again but the wanted index.
		if (i == index)
		{
			shapes[i]->clearDraw(_canvas);
		}
	}

	for (int i = 0; i < shapes.size(); i++)
	{
		// Print everything back again but the wanted index.
		if (i != index)
		{
			shapes[i]->draw(_canvas);
		}
	}

	if (delete_from_shapes)
		shapes.erase(shapes.begin() + index);

}

void Menu::deleteAllShapes(vector<Shape*>& shapes)
{
	// Your code here
}

