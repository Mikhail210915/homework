#include "Curve.h"

Point Curve::getPoint(double t)
{
	return Point(0, 0, 0);
};

Point Curve::getFirstDerivative(double t)
{
	return Point(0, 0, 0);
};

std::string Curve::getName()
{
	return curveName;
};

Curve::Curve(std::string name) : curveName(name)
{
	
}