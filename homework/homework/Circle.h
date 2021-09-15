#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Point.h"
#include "Curve.h"

class Circle : public Curve
{
public:
	double radius;

	Circle(double radius);

	virtual Point getPoint(double t) override;

	virtual Point getFirstDerivative(double t) override;

	virtual std::string getName() override;
};

#endif
