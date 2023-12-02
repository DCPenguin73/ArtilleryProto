/***********************************************************************
 * Source File:
 *    howitzer : Represents the howitzer in the artillery simulation
 * Author:
 *    Daniel Carr
 * Summary:
 *    What the howitzeer is 
 ************************************************************************/

#pragma once
#include "howitzer.h"
#include "angle.h"
#include "position.h"
#include "bullet.h"
#include <cassert>

//void set angle, double get angle, double get postion, void set posion, void fire bullet

//Howitzer::Howitzer(){}
void Howitzer::setRadian(double angleR) {
	angle.setRadians(angleR);
}
void Howitzer::setDegree(double angleD) {
	angle.setDegrees(angleD);
}
void Howitzer::setPosition(double x, double y) {
	position.setMetersX(x);
	position.setMetersY(y);
}
double Howitzer::getRadian() const {
	return angle.getRadians();
}
double Howitzer::getDegree() const {
	return angle.getDegrees();
}
Position Howitzer::getPosition() const {
	return position;
}
void Howitzer::fireBullet() {
	Bullet(position, 827, angle.getRadians(), 0);
}