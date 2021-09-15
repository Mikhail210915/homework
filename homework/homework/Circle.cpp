#include <iostream>
#include <exception>
#include "Circle.h"

Circle::Circle(double radius) : Curve("Circle")
{
	if (radius <= 0)
	{
		throw std::exception();
	}

	this->radius = radius;
}

Point Circle::getPoint(double t)
{
	double x = radius * cos(t);
	double y = radius * sin(t);

	return Point(x, y, 0);
}

Point Circle::getFirstDerivative(double t)
{
	double x = - radius * sin(t);
	double y = radius * cos(t);

	return Point(x, y, 0);
}

std::string Circle::getName()
{
	return curveName;
};

