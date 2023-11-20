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
	double getAngle() const;
	void setAngle(double angleR);
	double getPosition() const;
	void setPosition(double angleD);
	
	//fireBullet;


private:
	Position position;
	Angle angle;


};