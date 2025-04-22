#pragma once
#include "Shape.h"
#include <vector>
#include "Canvas.h"

class Menu
{
public:
	enum Shapes { circle, arrow, triangle, rectangle };
	enum Colors { red, green, blue };
	enum MainMenu { add_shape_choice, modify_shape_choice, delete_all_shapes, exit_choice };
	enum ModifyShapeMenu { move_shape, get_details, remove_shape };

	Menu();
	~Menu();

	void addCircle(std::vector<Shape*>& shapes);
	void addArrow(std::vector<Shape*>& shapes);
	void addTriangle(std::vector<Shape*>& shapes);
	void addRectangle(std::vector<Shape*>& shapes);

	void add_shape(std::vector<Shape*>& shapes);

	unsigned short displayChoicesMenu();

	unsigned short displayShapeObjectsMenu();

	void showAllShapes(std::vector<Shape*>& shapes);

	void showModifyShapeMenu(std::vector<Shape*>& shapes, unsigned short index);

	void moveShapeMenu(std::vector<Shape*>& shapes, unsigned short index);

	void removeShape(std::vector<Shape*>& shapes, unsigned short index, bool delete_from_shapes);

	void deleteAllShapes(std::vector<Shape*>& shapes);

private: 
	Canvas _canvas;
};

