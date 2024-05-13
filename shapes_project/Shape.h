//File: Shape.h

#include <string>
#include <vector>
#pragma once
using namespace std;

class Shape { //declaration of base class Shape
public: //virtual functions which declare all shapes can scale and display their data
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
};

class Shape2D : virtual public Shape { //declaration of base class Shape2D which derives from Shape class
public: //function prototypes and operator overload functions
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Shape3D : virtual public Shape { //declaration of base class Shape3D which derives from Shape class
public: //function prototypes and operator overload functions
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

class Square : public Shape2D //declaration of class Square which derives from Shape2D
{
	float side_ = 0; //data member side length
public: //function prototypes
	Square(); //default constructor
	Square(float side); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Rectangle : public Shape2D //declaration of class Rectangle which derives from Shape2D
{
	float length_ = 0; //data member length
	float width_ = 0; //data member width
public: //function prototypes
	Rectangle(); //default constructor
	Rectangle(float length, float width); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Triangle : public Shape2D //declaration of class Triangle which derives from Shape2D
{
	float base_ = 0; //data member base
	float height_ = 0; //data member height
public: //function prototypes
	Triangle(); //default constructor
	Triangle(float base, float height); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Circle : public Shape2D //declaration of class Circle which derives from Shape2D
{
	float radius_ = 0; //data member radius
public:
	Circle(); //default constructor
	Circle(float radius); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Elipse : public Shape2D //declaration of class Elipse which derives from Shape2D
{
	float minor_ = 0; //data member minor axis
	float major_ = 0; //data member major axis
public:
	Elipse(); //default constructor
	Elipse(float major_axis, float minor_axis); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Trapezoid : public Shape2D //declaration of class Trapezoid which derives from Shape2D
{
	float parallel_s1_ = 0; //data member parallel side 1
	float parallel_s2_ = 0; //data member parallel side 2
	float height_ = 0; //data member height
public: //function prototypes
	Trapezoid(); //defualt constructor
	Trapezoid(float parallel_side1, float parallel_side2, float height); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Sector : public Shape2D //declaration of class Sector which derives from Shape2D
{
	float radius_ = 0; //data member radius
	float angle_ = 0; //data member angle
public: //function prototypes
	Sector(); //default constructor
	Sector(float radius, float angle); //constructor
	float Area() const;
	string GetName2D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class TriangularPyramid : public Shape3D, private Triangle //declaraction of class TriangularPyramid which derives from Shape3D and privatley inherits the Triangle class
{
	float height_ = 0; //data member height

public: //function prototypes
	TriangularPyramid(); //default constructor
	TriangularPyramid(float height, float base_length, float base_height); //constructor
	float Volume() const;
	string GetName3D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class RectangularPyramid : public Shape3D, private Rectangle //declaraction of class RectangularPyramid which derives from Shape3D and privatley inherits the Rectangle class
{
	float height_ = 0; //data member height

public: //function prototypes
	RectangularPyramid(); //default constructor
	RectangularPyramid(float height, float base_length, float base_width); //constructor
	float Volume() const;
	string GetName3D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Cylinder : public Shape3D, private Circle //declaraction of class Cylinder which derives from Shape3D and privatley inherits the Circle class
{
	float height_ = 0; //data member height

public: //function prototypes
	Cylinder(); //default constructor
	Cylinder(float height, float radius); //constructor
	float Volume() const;
	string GetName3D() const;
	void Scale(float scalefactor);
	void Display() const;
};

class Sphere : public Shape3D, private Circle //declaraction of class Sphere which derives from Shape3D and privatley inherits the Circle class
{
	float radius_; //data member radius

public: //function prototypes
	Sphere(); //default constructor
	Sphere(float radius); //constructor
	float Volume() const;
	string GetName3D() const;
	void Scale(float scalefactor);
	void Display() const;
};


