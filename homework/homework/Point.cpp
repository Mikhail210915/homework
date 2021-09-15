#include "Point.h"

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

std::string Point::toString()
{
	char buf[50];
	sprintf_s(buf, 50, "{%.1f, %.1f, %.1f}", x, y, z);

	std::string str = buf;
	return str;
}