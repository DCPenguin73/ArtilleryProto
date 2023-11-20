#include <string>
using std::string;
#include "bullet.h"
#include "constants.h"
using namespace std;

/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
 // your function goes here
double Bullet::computeDistance(double s, double v, double a, double t) {
    double s2 = s + (v * t) + (0.5 * a * (t * t));
    return s2;
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
 // your function goes here
double Bullet::computeAcceleration(double f, double m) {
    double a = f / m;
    return a;
}

/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
 // your function goes here
double Bullet::computeVelocity(double v, double a, double t) {
    double v2 = v + (a * t);
    return v2;
}


/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
 // your function goes here
double Bullet::computeVertical(Angle a, double total) {
    double y = cos(a.getRadians()) * total;
    return y;
}

/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
 // your function goes here
double Bullet::computeHorizontal(Angle a, double total) {
    double x = sin(a.getRadians()) * total;
    return x;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double Bullet::computeTotal(double x, double y) {
    double total;
    total = sqrt(x * x + y * y);
    return total;
}

/****************************************************************
 * ANGLE FROM COMPONENTS
 * Get the new angle from the old angle and the horizonal and vertical speed
 ****************************************************************/
double Bullet::changeAngle(double horX, double verY) {
    return atan2(horX, verY);
}

/****************************************************************
 * DRAG FORCE EQUATION
 * Figure out how much drag there is on the projectile
 ****************************************************************/
double Bullet::dragForce(double coefficient, double density, double velocity, double area) {
    if (velocity > 0) {
        return .5 * coefficient * density * velocity * velocity * area * -1;
    }
    else {
        return .5 * coefficient * density * velocity * velocity * area;
    }

}
/****************************************************************
 * LINEAR INTERPOLATION
 * Take the coordinates of two points, and finds part the point in the middle
 ****************************************************************/
inline double Bullet::linearInter(double pos1X, double pos1Y, double pos2X, double pos2Y, double pointX) {
    return pos1Y + (pos2Y - pos1Y) * (pointX - pos1X) / (pos2X - pos1X);
}

/****************************************************************
 * BULLET MATH
 * Do all the calculations of the bullet moving, and move the bullet
 ****************************************************************/
Position Bullet::bulletMath() {
    angle.setRadians(changeAngle(xVel, yVel));
    mach = speed / speedSound.searchDatabase(location.getMetersY());
    drag = dragForce(dragCoef.searchDatabase(mach), airDensity.searchDatabase(location.getMetersY()), speed, surface_area) / WEIGHT;
    dragX = computeHorizontal(angle, drag);
    dragY = computeVertical(angle, drag);
    xAcc = dragX;
    yAcc = (gravity.searchDatabase(location.getMetersY()) * -1) + dragY;
    xVel = computeVelocity(xVel, xAcc, TIME_INTERVAL);
    yVel = computeVelocity(yVel, yAcc, TIME_INTERVAL);
    location.setMetersX(computeDistance(location.getMetersX(), xVel, xAcc, TIME_INTERVAL));
    location.setMetersY(computeDistance(location.getMetersY(), yVel, yAcc, TIME_INTERVAL));
    speed = computeTotal(xVel, yVel);
    return location;
}
