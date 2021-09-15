#include <exception>
#include "Ellipse.h"

Ellipse::Ellipse(double radiusX, double radiusY) : Curve("Ellipse")
{
	if ((radiusX <= 0) || (radiusY <= 0))
	{
		throw std::exception();
	}

	this->radiusX = radiusX;
	this->radiusY = radiusY;
}

Point Ellipse::getPoint(double t)
{
	double x = radiusX * cos(t);
	double y = radiusY * sin(t);

	return Point(x, y, 0);
}

Point Ellipse::getFirstDerivative(double t)
{
	double x = - radiusX * sin(t);
	double y = radiusY * cos(t);

	return Point(x, y, 0);
}

std::string Ellipse::getName()
{
	return curveName;
};


