#ifndef POINT_H
#define POINT_H

#include <string>

class Point
{
public:
	double x = 0;
	double y = 0;
	double z = 0;

	Point(double x, double y, double z);

	std::string toString();
};

#endif
