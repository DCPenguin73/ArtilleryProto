#pragma once

#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
	friend TestAngle;
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
	inline double display(std::ostream& out) const {
		out.setf(ios::fixed);     // "fixed" means don't use scientific notation
		out.setf(ios::showpoint); // "showpoint" means always show the decimal point
		out.precision(1);
		out << convertToDegrees(radians);
		return convertToDegrees(radians);
	}
	// Assignment Operators
	Angle& operator=(const Angle& rhs)
	{
		radians = rhs.radians;
		return *this;
	}
	Angle& operator=(double rhs)
	{
		radians = rhs;
		return *this;
	}
	// Negative Operator 
	Angle& operator-()
	{
		Angle rhs = *this;
		rhs.radians -= TWO_PI / 2;
		if (rhs.radians < 0) {
			rhs.radians += TWO_PI;
		}
		if (rhs.radians > TWO_PI) {
			rhs.radians -= TWO_PI;
		}
		return rhs;
	}
	// Increment Operators
	Angle& operator++()
	{
		radians = this->convertToRadians(this->getDegrees() + 1.0);
		radians = normalize(radians);
		// return new value
		return *this;
	}
	Angle& operator++(int postfix)
	{
		Angle numReturn = *this;
		radians = this->convertToRadians(this->getDegrees() + 1.0);
		radians = normalize(radians);
		// return new value
		return numReturn;
	}
	Angle& operator--()
	{
		radians = this->convertToRadians(this->getDegrees() - 1.0);
		radians = normalize(radians);
		// return new value
		return *this;
	}
	Angle& operator--(int postfix)
	{
		Angle numReturn = *this;
		radians = this->convertToRadians(this->getDegrees() - 1.0);
		radians = normalize(radians);
		// return new value
		return numReturn;
	}
private:
	double normalize(double angleR) const;
	double convertToDegrees(double radians) const;
	double convertToRadians(double degrees) const;
};

//bool operator==(const Angle& lhs, const Angle& rhs)
//{
//	return lhs.getRadians() == rhs.getRadians();
//}
//
//bool operator!=(const Angle& lhs, const Angle& rhs)
//{
//	return lhs.getRadians() != rhs.getRadians();
//}
//ostream& operator<<(ostream& out, const Angle& rhs)
//{
//	rhs.display(out);
//	return out;
//}
//istream& operator>>(istream& in,
//	Angle& rhs)
//{
//	double num;
//	if (in >> num) {
//		rhs.setDegrees(num);
//	}
//	return in;
//}