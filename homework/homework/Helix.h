#ifndef HELIX_H
#define HELIX_H

#include <string>
#include "Curve.h"
#include "Point.h"

class Helix : public Curve
{
public:
	double radius;
	double step;

	Helix(double radius, double step);

	virtual Point getPoint(double t) override;

	virtual Point getFirstDerivative(double t) override;

	virtual std::string getName() override;
};

#endif
