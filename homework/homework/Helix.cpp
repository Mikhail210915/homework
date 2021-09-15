#include <exception>
#include "Helix.h"
#include "MyMath.h"

Helix::Helix(double radius, double step) : Curve("Helix")
{
	if (radius <= 0)
	{
		throw std::exception();
	}

	this->radius = radius;
	this->step = step;
}

Point Helix::getPoint(double t)
{
	double x = radius * cos(t);
	double y = radius * sin(t);
	double z = t / (2 * PI) * step;

	return Point(x, y, z);
}

Point Helix::getFirstDerivative(double t)
{
	double x = - radius * sin(t);
	double y = radius * cos(t);
	double z = step / (2 * PI);

	return Point(x, y, z);
}

std::string Helix::getName()
{
	return curveName;
};

