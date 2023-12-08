#pragma once
#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
#include "angle.h"
#include "position.h"
#include "Database.h"
#define PI 3.1415926535
#define TIME_INTERVAL .1

#define WEIGHT        46.7   // Weight in KG



using namespace std;
class TestBullet;
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
		angle = aAngle;
		xVel = computeHorizontal(aAngle, aSpeed);
		yVel = computeVertical(aAngle, aSpeed);;
		speed = aSpeed;
		mach = 0;
		age = aAge;
		drag = 0;
		dragX = 0;
		dragY = 0;
	}
private:
	double computeDistance(double s, double v, double a, double t);
	double computeAcceleration(double f, double m);
	double computeVelocity(double v, double a, double t);
	double computeVertical(Angle a, double total);
	double computeHorizontal(Angle a, double total);
	double computeTotal(double x, double y);
	double changeAngle(double horX, double verY);
	double dragForce(double coefficient, double density, double velocity, double area);
	double linearInter(double pos1X, double pos1Y, double pos2X, double pos2Y, double pointX);
public:
	Position bulletMath();
	double getAge();
	void endMove();
	double getSpeed();
	double getX();
	Position getPosition();
};

