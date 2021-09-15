#ifndef CURVE_H
#define CURVE_H

#include <string>
#include "Point.h"

/// <summary>
/// Parent class for all curves
/// </summary>
class Curve
{
public:
	std::string curveName;  // Ñurve type name  

	Curve(std::string name);

	// Get the 3D point per parameter t (angle value in radians) along the curve
	virtual Point getPoint(double t);

	// Get the 3D point corresponding to the first derivative per parameter t (angle value in radians) along the curve 
	virtual Point getFirstDerivative(double t);

	virtual std::string getName();
};

#endif
