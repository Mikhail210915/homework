#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <string>
#include "Curve.h"
#include "Point.h"

class Ellipse : public Curve
{
public:
	double radiusX;
	double radiusY;

	Ellipse(double radiusX, double radiusY);

	virtual  Point getPoint(double t) override;

	virtual Point getFirstDerivative(double t) override;

	virtual std::string getName() override;
};

#endif