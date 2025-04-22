#include "Menu.h"
#include <iostream>

void main()
{

	std::vector<Shape*> shapes;
	Menu mn;

	while (true) 
	{
		try 
		{ 
			unsigned short choice = mn.displayChoicesMenu();
			
			switch (choice) 
			{
				case mn.add_shape_choice: 
					mn.add_shape(shapes); 
					break;
				case mn.modify_shape_choice: 
					mn.showAllShapes(shapes); 
					break;
				case mn.delete_all_shapes: 
					mn.deleteAllShapes(shapes); 
					break;
				case mn.exit_choice: 
					exit(0); 
					break;
			}
		}
		catch(std::exception e) 
		{
			std::cout << e.what() << std::endl;
			system("PAUSE");
		}
	}
}