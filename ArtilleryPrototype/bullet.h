#pragma once
#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include "angle.h"
#include "position.h"
using namespace std;

/************************************
 * BULLET
 ************************************/
class Bullet {
private:
	Position location;
	double xAcc;
	double yAcc;
	double xVel;
	double yVel;
	Angle angle;
	double speed;
	double mach;
	double age;
	double drag;
	double dragX;
	double dragY;
public:
	Bullet() {
		location = Position(0, 0);
		xAcc = 0;
		yAcc = 0;
		xVel = 0;
		yVel = 0;
		angle = Angle(0);
		speed = 0;
		mach = 0;
		age = 0;
		drag = 0;
		dragX = 0;
		dragY = 0;
	}
	Bullet()
};