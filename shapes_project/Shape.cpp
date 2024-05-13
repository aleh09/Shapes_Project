//file: Shape.cpp

#define _USE_MATH_DEFINES

#include "Shape.h"
#include <string>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

bool Shape2D::operator>(const Shape2D& rhs) const //operator overload function for > that compares 2D shapes areas
{
	return Area() > rhs.Area();
}

bool Shape2D::operator<(const Shape2D& rhs) const //operator overload function for < that compares 2D shapes areas
{
	return Area() < rhs.Area();
}

bool Shape2D::operator==(const Shape2D& rhs) const //operator overload function for == that compares 2D shapes areas
{
	return Area() == rhs.Area();
}

void Shape2D::ShowArea() const //shows the area of a given shape
{
	cout << "Area: " << Area();
}

Square::Square() //default constructor for square
{
	side_ = 0.f;
}

Square::Square(float side) //constructor for square that takes in side length and sets it to data member
{
	side_ = side;
}

float Square::Area() const //calculates square area
{
	return side_ * side_;
}

string Square::GetName2D() const //gets name of square
{
	return "Square ";
}

void Square::Scale(float scalefactor) //scales square side
{
	side_ *= scalefactor;
}

void Square::Display() const //displays square name and area
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}


Rectangle::Rectangle() //default rectangle constructor
{
	length_ = 0.f;
	width_ = 0.f;
}

Rectangle::Rectangle(float length, float width) //constructor for rectangle takes in length and width and sets them to data members
{
	length_ = length;
	width_ = width;
}

float Rectangle::Area() const //calculates rectangle area
{
	return length_ * width_;
}

string Rectangle::GetName2D() const //gets rectangle name
{
	return "Rectangle ";
}

void Rectangle::Scale(float scalefactor) //scales width and length of rectangle
{
	length_ *= scalefactor;
	width_ *= scalefactor;
}

void Rectangle::Display() const //displays name and area of rectangle
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}

Triangle::Triangle() //default constructor for triangle
{
	base_ = 0.f;
	height_ = 0.f;
}

Triangle::Triangle(float base, float height) //constructor for triangle that takes in base and height and sets it to data members
{
	base_ = base;
	height_ = height;
}

float Triangle::Area() const //calculates area of triangle
{
	return (.5 * base_ * height_);
}

string Triangle::GetName2D() const //gets triangle name
{
	return "Triangle ";
}

void Triangle::Scale(float scalefactor) //scales triangle base and height
{
	base_ *= scalefactor;
	height_ *= scalefactor;
}

void Triangle::Display() const //displays name and area of triangle
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}

Circle::Circle() //default constructor for circle
{
	radius_ = 0.f;
}

Circle::Circle(float radius) //constructor for circle takse in radius and sets it to data member
{
	radius_ = radius;
}

float Circle::Area() const //calculates triangle area
{
	return (M_PI * powf(radius_, 2));
}

string Circle::GetName2D() const //gets name of triangle
{
	return "Circle ";
}

void Circle::Scale(float scalefactor) //scales radius of triangle
{
	radius_ *= scalefactor;
	Area();
}

void Circle::Display() const //displays name and area of triangle
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}

Elipse::Elipse() //default constructor for elipse
{
	major_ = 0.f;
	minor_ = 0.f;
}

Elipse::Elipse(float major_axis, float minor_axis) //constructor for elipse takes in major axis and minor axis and sets them to data member
{
	major_ = major_axis;
	minor_ = minor_axis;
}

float Elipse::Area() const //calculates elipse area
{
	return (M_PI * major_ * minor_);
}

string Elipse::GetName2D() const //gets elipse name
{
	return "Elipse ";
}

void Elipse::Scale(float scalefactor) //scales major and minor axis of elipse
{
	major_ *= scalefactor;
	minor_ *= scalefactor;
	Area();
}

void Elipse::Display() const //displays name and area of elipse
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}

Trapezoid::Trapezoid() //default constructor for trapezoid
{
	parallel_s1_ = 0.f;
	parallel_s2_ = 0.f;
	height_ = 0.f;
}

Trapezoid::Trapezoid(float parallel_side1, float parallel_side2, float height) //constructor for trapezoid takes in parrallel side 1, parallel side 2, and height and sets them to data members
{
	parallel_s1_ = parallel_side1;
	parallel_s2_ = parallel_side2;
	height_ = height;
}

float Trapezoid::Area() const //calculates area of trapezoid
{
	return (((parallel_s1_ * parallel_s2_) / 2) * height_);
}

string Trapezoid::GetName2D() const //gets name of trapezoid
{
	return "Trapezoid ";
}

void Trapezoid::Scale(float scalefactor) //scales parallel side 2, parallel side 2, and height of trapezoid
{
	parallel_s1_ *= scalefactor;
	parallel_s2_ *= scalefactor;
	height_ *= scalefactor;
}

void Trapezoid::Display() const //displays name and area of trapezoid
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}

Sector::Sector() //default constructor for sector
{
	radius_ = 0.f;
	angle_ = 0.f;
}

Sector::Sector(float radius, float angle) //constructor for sector takes in radius and angle (in degrees) and set them to data members
{
	radius_ = radius;
	angle_ = (angle * (M_PI / 180)); //converts degrees to radians
}

float Sector::Area() const //calculates area of sector
{
	return (.5 * (powf(radius_, 2) * angle_));
}

string Sector::GetName2D() const //gets name of sector
{
	return "Sector ";
}

void Sector::Scale(float scalefactor) //scales radius and angle of sector
{
	radius_ *= scalefactor;
	angle_ *= scalefactor;
}

void Sector::Display() const //displays name and area of sector
{
	cout << GetName2D();
	ShowArea();
	cout << endl;
}

bool Shape3D::operator>(const Shape3D& rhs) const //operator overload function for > which compares 3D shapes volumes
{
	return Volume() > rhs.Volume();
}

bool Shape3D::operator<(const Shape3D& rhs) const //operator overload function for < which compares 3D shapes volumes
{
	return Volume() < rhs.Volume();
}

bool Shape3D::operator==(const Shape3D& rhs) const //operator overload function for == which compares 3D shapes volumes
{
	return Volume() == rhs.Volume();
}

void Shape3D::ShowVolume() const //shows 3D shapes volume
{
	cout << "Volume: " << Volume();
}

TriangularPyramid::TriangularPyramid() //default constructor for triangular pyramid
{
	height_ = 0.f;
}

TriangularPyramid::TriangularPyramid(float height, float base_length, float base_height) : Triangle(base_length, base_height),height_(height) //constructor for triangular pyramid which takes in height, base length, and base height then sets them to the data members of the class and of the triangle class
{
}

float TriangularPyramid::Volume() const //calculates volume of a triangular pyramid using the area function in the triangle class
{
	return (Area() * height_) / 3;

}

string TriangularPyramid::GetName3D() const //gets triangular pyramid name
{
	return "Triangular Pyramid ";
}

void TriangularPyramid::Scale(float scalefactor) //scales triangular pyramid height
{
	height_ *= scalefactor;
}

void TriangularPyramid::Display() const //displays name and volume of triangular pyramid
{
	cout << GetName3D();
	ShowVolume();
	cout << endl;
}

RectangularPyramid::RectangularPyramid() //default constructor for rectangular pyramid
{
	height_ = 0.f;
}

RectangularPyramid::RectangularPyramid(float height, float base_length, float base_width) : Rectangle(base_length, base_width),height_(height) //constructor for rectangular pyramid which takes in height, base length, and base width then sets them to the data members of the class and of the rectangle class
{
}

float RectangularPyramid::Volume() const //calculates volume of rectangular pyramid using the area function in the rectangle class
{
	return (Area() * height_) / 3;
}

string RectangularPyramid::GetName3D() const //gets name of rectangular pyramid
{
	return "Rectangular Pyramid ";
}

void RectangularPyramid::Scale(float scalefactor) //scales height of the rectangular pyramid
{
	height_ *= scalefactor;
}

void RectangularPyramid::Display() const //displays the name and volume of the rectangular pyramid
{
	cout << GetName3D();
	ShowVolume();
	cout << endl;
}

Cylinder::Cylinder() //default constructor for cylinder
{
	height_ = 0.f;
}

Cylinder::Cylinder(float height, float radius) : Circle(radius), height_(height) //constructor for cylinder which takes in height and radius then sets them to the data members of the class and the data members of the circle class
{
}

float Cylinder::Volume() const //calculates the volume of the cylinder using the area function of the circle class
{
	return Area() * height_;
}

string Cylinder::GetName3D() const //gets the name of the cylinder
{
	return "Cylinder ";
}

void Cylinder::Scale(float scalefactor) //scales the height of the cylinder
{
	height_ *= scalefactor;
}

void Cylinder::Display() const //displays the name and volume of the cylinder
{
	cout << GetName3D();
	ShowVolume();
	cout << endl;
}

Sphere::Sphere() //default constructor for sphere
{
	radius_ = 0.f;
}

Sphere::Sphere(float radius) : Circle(radius),radius_(radius) //constructor for sphere which takes in radius and sets it to the data member of the class and the data member of the circle class
{
}

float Sphere::Volume() const //calculates the volume of the sphere using the area function in the circle class
{
	return (4 * M_PI * pow(radius_, 3)) / 3;
}

string Sphere::GetName3D() const //gets the name of the sphere
{
	return "Sphere ";
}

void Sphere::Scale(float scalefactor) //scales the radius of the sphere
{
	radius_ *= scalefactor;
}

void Sphere::Display() const //diplays the name and volume of the sphere
{
	cout << GetName3D();
	ShowVolume();
	cout << endl;
}
