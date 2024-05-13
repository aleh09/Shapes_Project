/* Author: Andy Lehmann | student ID: 1788709 | Email: andrew.lehmann@snhu.edu
Project: Inheritance & polymorphism
Description: Create a series of classes to represent simple 2D and 3D
shapes. The classes will use inheritance & polymorphism to store and use separate classes.
Some classes make use of multiple inheritance, as well as private inheritance. The program 
provides a menu-based user interface that allows the user to create lists of 2D and 3D shapes
and perform actions on those lists.
*/

#include "Shape.h"
#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector<Shape*> shapes; //vector for 3D and 2D shapes
	vector<Shape2D*> shapes2D; //vector for 2D shapes
	vector<Shape3D*> shapes3D; //vector for 3D shapes
	int decision; //variable to keep track of user decision
	//float variables to take in lengths needed to calculate different shape areas and volumes
	float side;
	float length;
	float width;
	float base;
	float height;
	float radius;
	float minor_axis;
	float major_axis;
	float parrallel_s1;
	float parrallel_s2;
	float angle;
	float base_length;
	float base_height;
	float base_width;
	float scaleFactor; //variable to scale 2D and 3D shapes
	//variables for binary search algorithm
	int high3D;
	int low3D;
	int high2D;
	int low2D;
	int mid2D;
	int mid3D;
	cout << "Hello Welcome to the Shapes Application!" << endl << endl;
	do { //main navigation UI 
		cout << "Type the Number for the Action you want to do:" << endl << endl;
		cout << "[1] Create a list of 2D shapes" << endl;
		cout << "[2] Create a list of 3D shapes" << endl;
		cout << "[3] Create a list of 2D and 3D shapes" << endl;
		cout << "[0] Exit" << endl;
		cin >> decision;
		switch (decision) //based on decision it will go to the different UI for which list user wants to create
		{
		case 1:
			do { //UI for user to create a list of 2D shapes and perform actions on that list
				cout << "Type the Number for the Action you want to do:" << endl << endl;
				cout << "[1] Add a Square" << endl;
				cout << "[2] Add a Rectangle" << endl;
				cout << "[3] Add a Triangle" << endl;
				cout << "[4] Add a Circle" << endl;
				cout << "[5] Add an Ellipse" << endl;
				cout << "[6] Add a Trapezoid" << endl;
				cout << "[7] Add a Sector" << endl;
				cout << "[8] Display 2D Shapes" << endl;
				cout << "[9] Get Smallest and Largest Shape by Area" << endl;
				cout << "[10] Sort Shapes by Size" << endl;
				cout << "[11] Search for a Shape that has an area greater than or equal to a given area" << endl;
				cout << "[-1] Go Back" << endl;
				cin >> decision;
				switch (decision) //based on decsision it will go to the case of the action the user wants to perform
				{
				case 1: //adds a square to 2D shapes vector
					cout << "Enter side length: ";
					cin >> side;
					shapes2D.push_back(new Square(side));
					cout << "Square Created!" << endl << endl;
					break;
				case 2: //adds a rectangle to 2D shapes vector
					cout << "Enter length: ";
					cin >> length;
					cout << "Enter width: ";
					cin >> width;
					shapes2D.push_back(new Rectangle(length, width));
					cout << "Rectangle Created!" << endl << endl;
					break;
				case 3: //adds a triangle to 2D shapes vector
					cout << "Enter base: ";
					cin >> base;
					cout << "Enter height: ";
					cin >> height;
					shapes2D.push_back(new Triangle(base, height));
					cout << "Triangle Created!" << endl << endl;
					break;
				case 4: //adds a circle to 2D shapes vector
					cout << "Enter radius: ";
					cin >> radius;
					shapes2D.push_back(new Circle(radius));
					cout << "Circle Created!" << endl << endl;
					break;
				case 5: //adds an elipse to 2D shapes vector
					cout << "Enter major axis: ";
					cin >> major_axis;
					cout << "Enter minor axis: ";
					cin >> minor_axis;
					shapes2D.push_back(new Elipse(major_axis, minor_axis));
					cout << "Elipse Created!" << endl << endl;
					break;
				case 6: //adds a trapezoid to 2D shapes vector
					cout << "Enter side 1: ";
					cin >> parrallel_s1;
					cout << "Enter side 2: ";
					cin >> parrallel_s2;
					cout << "Enter height: ";
					cin >> height;
					shapes2D.push_back(new Trapezoid(parrallel_s1, parrallel_s2, height));
					cout << "Trapezoid Created!" << endl << endl;
					break;
				case 7: //adds a sector to 2D shapes vector
					cout << "Enter radius: ";
					cin >> radius;
					cout << "Enter angle (in degrees): ";
					cin >> angle;
					shapes2D.push_back(new Sector(radius, angle));
					cout << "Sector Created!" << endl << endl;
					break;
				case 8: //displays all 2D shapes in the 2D shapes vector, showing the name of the shape and its area
					for (unsigned int i = 0; i < shapes2D.size(); i++)
					{
						shapes2D[i]->Display();
					}
					break;
				case 9: //finds the min and max area in the 2D shapes vector
					Shape2D * max;
					Shape2D* min;
					max = shapes2D[0];
					min = shapes2D[0];

					//Find maximum and minimum in all array elements.
					for (int i = 1; i < shapes2D.size(); i++)
					{
						//If current element is greater than max
						if (*shapes2D[i] > *max)
						{
							max = shapes2D[i];
						}
						//If current element is smaller than min
						if (*shapes2D[i] < *min)
						{
							min = shapes2D[i];
						}
					}
					//displays min and max
					cout << "Min:" << endl;
					min->Display();
					cout << "Max:" << endl;
					max->Display();
					break;
				case 10: //Sorts shapes by area from smallest to largest
					int i, j;
					Shape2D* hold;
					for (i = 1; i < shapes2D.size(); i++) {
						hold = shapes2D[i];
						j = i - 1;
						//Move elements of arr[0..i-1], that are greater than key, to one
						//position ahead of their current position
						while (j >= 0 && *shapes2D[j] > *hold) {
							shapes2D[j + 1] = shapes2D[j];
							j = j - 1;
						}
						shapes2D[j + 1] = hold;
					}
					cout << "2D Shapes Sorted!" << endl;
					break;
				case 11: //first sorts shapes then uses binary search to find area of a shape that is greater than or equal to user inputted area
					//sorts shapes
					for (i = 1; i < shapes2D.size(); i++) {
						hold = shapes2D[i];
						j = i - 1;
						//Move elements of arr[0..i-1], that are greater than key, to one
						//position ahead of their current position
						while (j >= 0 && *shapes2D[j] > *hold) {
							shapes2D[j + 1] = shapes2D[j];
							j = j - 1;
						}
						shapes2D[j + 1] = hold;
					}
					//binary search to find area of a shape that is greater than or equal to user inputted area
					float area;
					low2D = 0;
					high2D = shapes2D.size();
					mid2D = shapes2D.size() / 2;
					cout << "Enter Area: ";
					cin >> area;
					//Repeat until the low and high meet each other
					while (low2D <= high2D) {
						mid2D = low2D + (high2D - low2D) / 2;
						if (shapes2D[mid2D]->Area() == area)
						{
							cout << "Shape Found!" << endl;
							shapes2D[mid2D]->Display();
						}
						if (shapes2D[mid2D]->Area() < area)
						{
							low2D = mid2D + 1;
						}
						else
						{
							high2D = mid2D - 1;
						}
					}
					if (shapes2D[mid2D]->Area() > area) //if the given area does not equal an area in the shape vector then it displays the first shape with an area greater than that area
					{
						cout << "Shape Found!" << endl;
						shapes2D[mid2D]->Display();
					}
					break;	
				case -1: //breaks do while loop and goes back to main UI
					decision = -1;
					break;
				}

			} while (decision != -1);
			break;
		case 2:
			do{//UI for user to create a list of 3D shapes and perform actions on that list
				cout << "Type the Number for the Action you want to do:" << endl << endl;
				cout << "[1] Add a Triangular Pyramid" << endl;
				cout << "[2] Add a Rectangular Pyramid" << endl;
				cout << "[3] Add a Cylinder" << endl;
				cout << "[4] Add a Sphere" << endl;
				cout << "[5] Display 3D Shapes" << endl;
				cout << "[6] Get Smallest and Largest Shape by Volume" << endl;
				cout << "[7] Sort Shapes by Size" << endl;
				cout << "[8] Search for a Shape that has an volume greater than or equal to a given volume" << endl;
				cout << "[-1] Go Back" << endl;
				cin >> decision;
				switch (decision) //based on user decision it will either add 3D shape to the 3D shape vector or perform an action on the 3D shape vector
				{
				case 1: //adds a triangular pyramid to the 3D shapes vector
					cout << "Enter height: ";
					cin >> height;
					cout << "Enter base length: ";
					cin >> base_length;
					cout << "Enter base height: ";
					cin >> base_height;
					shapes3D.push_back(new TriangularPyramid(height, base_length, base_height));
					cout << "Triangular Pyramid Created!" << endl << endl;
					break;
				case 2: //adds a rectangular pyramid to the 3D shapes vector
					cout << "Enter height: ";
					cin >> height;
					cout << "Enter base length: ";
					cin >> base_length;
					cout << "Enter base width: ";
					cin >> base_width;
					shapes3D.push_back(new RectangularPyramid(height, base_length, base_width));
					cout << "Rectangular Pyramid Created!" << endl << endl;
					break;
				case 3: //adds a cylinder to the 3D shapes vector
					cout << "Enter height: ";
					cin >> height;
					cout << "Enter radius: ";
					cin >> radius;
					shapes3D.push_back(new Cylinder(height, radius));
					cout << "Cylinder Created!" << endl << endl;
					break;
				case 4: //adds a sphere to the 3D shapes vector
					cout << "Enter radius: ";
					cin >> radius;
					shapes3D.push_back(new Sphere(radius));
					cout << "Sphere Created!" << endl << endl;
					break;
				case 5: //displays the 3D shapes name and volume of all the 3D shapes in the vector
					for (unsigned int i = 0; i < shapes3D.size(); i++)
					{
						shapes3D[i]->Display();
					}
					break;
				case 6: //finds the min and max volume in the 3D shapes vector
					Shape3D* max;
					Shape3D* min;
					max = shapes3D[0];
					min = shapes3D[0];

					//Find maximum and minimum in all array elements.
					for (int i = 1; i < shapes3D.size(); i++)
					{
						//If current element is greater than max
						if (*shapes3D[i] > *max)
						{
							max = shapes3D[i];
						}
						//If current element is smaller than min
						if (*shapes3D[i] < *min)
						{
							min = shapes3D[i];
						}
					}
					//displays the 3D shapes with the min and max volume
					cout << "Min:" << endl;
					min->Display();
					cout << "Max:" << endl;
					max->Display();
					break;
				case 7: //sorts the 3D shapes in the vector by volume from smallest to largest
					int i, j;
					Shape3D* hold;
					for (i = 1; i < shapes3D.size(); i++) {
						hold = shapes3D[i];
						j = i - 1;
						//Move elements of arr[0..i-1], that are greater than key, to one
						//position ahead of their current position
						while (j >= 0 && *shapes3D[j] > *hold) {
							shapes3D[j + 1] = shapes3D[j];
							j = j - 1;
						}
						shapes3D[j + 1] = hold;
					}
					cout << "3D Shapes Sorted!" << endl;
					break;
				case 8:
					//sorts 3D shapes
					for (i = 1; i < shapes3D.size(); i++) {
						hold = shapes3D[i];
						j = i - 1;
						//Move elements of arr[0..i-1], that are greater than key, to one
						//position ahead of their current position
						while (j >= 0 && *shapes3D[j] > *hold) {
							shapes3D[j + 1] = shapes3D[j];
							j = j - 1;
						}
						shapes3D[j + 1] = hold;
					}
					float volume;
					low3D = 0;
					high3D = shapes3D.size();
					mid3D = shapes3D.size() / 2;
					cout << "Enter Volume: ";
					cin >> volume;
					//Repeat until the low and high meet each other
					while (low3D <= high3D) {
						mid3D = low3D + (high3D - low3D) / 2;
						if (shapes3D[mid3D]->Volume() == volume)
						{
							cout << "Shape Found!" << endl;
							shapes3D[mid3D]->Display();
						}
						if (shapes3D[mid3D]->Volume() < volume)
						{
							low3D = mid3D + 1;
						}
						else
						{
							high3D = mid3D - 1;
						}
					}
					if (shapes3D[mid3D]->Volume() > volume) //if the given volume does not equal a volume in the 3D shape vector then it displays the first shape with a volume greater than that volume
					{
						cout << "Shape Found!" << endl;
						shapes3D[mid3D]->Display();
					}
					break;	
				case -1: //breaks the do while loop and goes back to the main UI
					decision = -1;
					break;
				}
			} while (decision != -1);
			break;
		case 3:
			do{ //UI for user to create a list of 2D and 3D shapes and perform actions on that list
				cout << "Type the Number for the Action you want to do:" << endl << endl;
				cout << "[1] Add a Square" << endl;
				cout << "[2] Add a Rectangle" << endl;
				cout << "[3] Add a Triangle" << endl;
				cout << "[4] Add a Circle" << endl;
				cout << "[5] Add an Ellipse" << endl;
				cout << "[6] Add a Trapezoid" << endl;
				cout << "[7] Add a Sector" << endl;
				cout << "[8] Add a Triangular Pyramid" << endl;
				cout << "[9] Add a Rectangular Pyramid" << endl;
				cout << "[10] Add a Cylinder" << endl;
				cout << "[11] Add a Sphere" << endl;
				cout << "[12] Display 2D/3D Shapes" << endl;
				cout << "[13] Scale Shapes" << endl;
				cout << "[-1] Go Back" << endl;
				cin >> decision;
				switch (decision) //based on the decsion it will go to the case to perform that action
				{
				case 1: //adds square to shapes vector
					cout << "Enter side length: ";
					cin >> side;
					shapes.push_back(new Square(side));
					cout << "Square Created!" << endl << endl;
					break;
				case 2: //adds rectangle to shapes vector
					cout << "Enter length: ";
					cin >> length;
					cout << "Enter width: ";
					cin >> width;
					shapes.push_back(new Rectangle(length, width));
					cout << "Rectangle Created!" << endl << endl;
					break;
				case 3: //adds triangle to shapes vector
					cout << "Enter base: ";
					cin >> base;
					cout << "Enter height: ";
					cin >> height;
					shapes.push_back(new Triangle(base, height));
					cout << "Triangle Created!" << endl << endl;
					break;
				case 4: //adds circle to shapes vector
					cout << "Enter radius: ";
					cin >> radius;
					shapes.push_back(new Circle(radius));
					cout << "Circle Created!" << endl << endl;
					break;
				case 5: //adds elipse to shapes vector
					cout << "Enter major axis: ";
					cin >> major_axis;
					cout << "Enter minor axis: ";
					cin >> minor_axis;
					shapes.push_back(new Elipse(major_axis, minor_axis));
					cout << "Elipse Created!" << endl << endl;
					break;
				case 6: //adds trapezoid to shapes vector
					cout << "Enter side 1: ";
					cin >> parrallel_s1;
					cout << "Enter side 2: ";
					cin >> parrallel_s2;
					cout << "Enter height: ";
					cin >> height;
					shapes.push_back(new Trapezoid(parrallel_s1, parrallel_s2, height));
					cout << "Trapezoid Created!" << endl << endl;
					break;
				case 7: //adds elipse to shapes vector
					cout << "Enter radius: ";
					cin >> radius;
					cout << "Enter angle (in degrees): ";
					cin >> angle;
					shapes.push_back(new Sector(radius, angle));
					cout << "Sector Created!" << endl << endl;
					break;
				case 8: //adds triangular pyramid to shapes vector
					cout << "Enter height: ";
					cin >> height;
					cout << "Enter base length: ";
					cin >> base_length;
					cout << "Enter base height: ";
					cin >> base_height;
					shapes.push_back(new TriangularPyramid(height, base_length, base_height));
					cout << "Triangular Pyramid Created!" << endl << endl;
					break;
				case 9: //adds rectangular pyramid to shapes vector
					cout << "Enter height: ";
					cin >> height;
					cout << "Enter base length: ";
					cin >> base_length;
					cout << "Enter base width: ";
					cin >> base_width;
					shapes.push_back(new RectangularPyramid(height, base_length, base_width));
					cout << "Rectangular Pyramid Created!" << endl << endl;
					break;
				case 10: //adds cylinder to shapes vector
					cout << "Enter height: ";
					cin >> height;
					cout << "Enter radius: ";
					cin >> radius;
					shapes.push_back(new Cylinder(height, radius));
					cout << "Cylinder Created!" << endl << endl;
					break;
				case 11: //adds sphere to shapes vector
					cout << "Enter radius: ";
					cin >> radius;
					shapes.push_back(new Sphere(radius));
					cout << "Sphere Created!" << endl << endl;
					break;
				case 12: //displays all the shapes in shapes vector giving its name and volume/area
					for (unsigned int i = 0; i < shapes.size(); i++)
					{
						shapes[i]->Display();
					}
					break;
				case 13: //scales all shapes in shapes vector by a scale factor entered by user
					cout << "Enter scale factor: ";
					cin >> scaleFactor;
					cout << "Scaling..." << endl << endl;
					for (unsigned int i = 0; i < shapes.size(); i++) 
					{
						shapes[i]->Scale(scaleFactor);
						shapes[i]->Display();
						cout << endl;
					}
					break;
				case -1: //breaks the do while loop and goes back to the main UI
					decision = -1;
					break;
				}
			} while (decision != -1);
			break;
		case 0: //breaks the do while loop and exits the program;
			decision = 0;
			break;
		}
	} while (decision != 0);
}
