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
public: 
	friend TestBullet;
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
	Bullet(const Bullet& copier) {
		location = copier.location;
		xAcc = copier.xAcc;
		yAcc = copier.yAcc;
		xVel = copier.xVel;
		yVel = copier.yVel;
		angle = copier.angle;
		speed = copier.speed;
		mach = copier.mach;
		age = copier.age;
		drag = copier.drag;
		dragX = copier.dragX;
		dragY = copier.dragY;
	}
	Bullet(Position aLocation, double aSpeed, Angle aAngle, double aAge) {
		location = aLocation;
		xAcc = 0;
		yAcc = 0;
		xVel = 0;
		yVel = 0;
		angle = aAngle;
		speed = aSpeed;
		mach = 0;
		age = aAge;
		drag = 0;
		dragX = 0;
		dragY = 0;
	}

};