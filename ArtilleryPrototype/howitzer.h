#pragma once
/***********************************************************************
 * Header File:
 *    Howitzer : The gun
 * Author:
 *    Daniel Carr
 * Summary:
 *    Everything about the gun
 ************************************************************************/

#include <iostream> 
#include <cmath>
#include <cassert>
#include "position.h"   // for Point
#include "angle.h"
#include "bullet.h"

using namespace std;

/*************************************************************************
* Howitzer
* The gun on the screen
**************************************************************************/
class Howitzer
{

/// <summary>
/// position, angle, set angle, get angle, get postion, set posion, fire bullet
/// </summary>
public:
	Howitzer() {
		angle.setDegrees(44.5);
	}
	double getRadian() const;
	double getDegree() const;
	void setRadian(double angleR);
	void setDegree(double angleD);
	Position getPosition() const;
	void setPosition(double x, double y);
	
	void fireBullet();


private:
	Position position;
	Angle angle;
	Bullet bullet;


};