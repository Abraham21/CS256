// Quiz2.cpp
// Abraham Yepremian
// write a program that demonstrates the Circle class by asking
// the user for the radius, creating a Circle object, and then
// reporting the circle's area, diameter, and circumference
//

#include "stdafx.h"
#include <string> //this allows me to use string objects
#include <iostream>

using namespace std;

class Circle {
private: 
	double radius;
	double pi = 3.14159;
public: 
	//default constructor
	Circle() {
		radius = 0.0;
	}
	//constructor
	Circle(double r) {
		radius = r;
	}

	//setters or mutators
	void setRadius(double r) {
		radius = r;
	}

	//getters or accessors
	double getRadius() {
		return radius;
	}

	double getArea() {
		return pi * radius * radius;
	}

	double getDiameter() {
		return radius * 2;
	}

	double getCircumference() {
		return 2 * pi * radius;
	}
};

int main()
{
	//get user input for radius
	double radiusInput;
	cout << "Enter the circle's radius:" << endl;
	cin >> radiusInput;

	//create Circle object with desired radius
	Circle circle(radiusInput);

	//print out using the getter/accessor methods
	cout << "Area: " << circle.getArea() << endl;
	cout << "Diameter: " << circle.getDiameter() << endl;
	cout << "Circumference: " << circle.getCircumference() << endl;

    return 0;
}

