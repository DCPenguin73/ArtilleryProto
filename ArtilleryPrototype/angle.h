#pragma once

#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;


/************************************
 * ANGLE
 ************************************/
class Angle
{
private:
	double radians;
public:
	Angle()
	{
		radians = 0.0;
	}
	Angle(const Angle& copier)
	{
		radians = copier.radians;
	}
	Angle(double inputDeg)
	{
		radians = convertToRadians(inputDeg);
	}
public:
	double getRadians() const;
	void setRadians(double angleR);
	double getDegrees() const;
	void setDegrees(double angleD);
private:
	double normalize(double angleR) const;
	double convertToDegrees(double radians) const;
	double convertToRadians(double degrees) const;
};

