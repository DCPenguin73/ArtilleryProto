/***********************************************************************
 * Header File:
 *    Test Angle : Test the Angle class
 * Author:
 *    Daniel Carr
 * Summary:
 *    All the unit tests for the Angle class
 ************************************************************************/


#pragma once

#include "angle.h"
#include <cassert>
#include <vector>
#define TWO_PI 6.28318530718



using namespace std;

/*******************************
 * TEST Angle
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle
{
public:
    void run()
    {
        defaultConstructor();
        nonDefaultConstructor();
        
        //convertToDegrees();
        //convertToRadians();
        //normalize();
        //getRadians();
        //getDegrees();
        //setRadians();
        //setDegrees();
    }

private:
    // Test the default constructor
    void  defaultConstructor()
    {   // setup
        // exercise
        Angle angle;
        // verify
        assert(angle.radians == 0);
    }  // teardown

    void nonDefaultConstructor() 
        {  // setup
            // exercise
            Angle angle = Angle(180);
            // verify
            assert(angle.radians == 2);
        }  // teardown
    //void convertToDegrees(){
    //    convertToDegreesZero();
    //    convertToDegreesPi();
    //}
    //void convertToRadians() {
    //    convertToRadiansZero();
    //    convertToRadians180();
    //}
    //void normalize() {
    //    normalizeNoChange();
    //    normalizeNegativePi();
    //    normalizeSevenPi();
    //}
    //void getRadians() {
    //    getRadiansZero();
    //    getRadiansPi();
    //}
    //void getDegrees() {
    //    getDegreesZero();
    //    getDegreesPi();
    //}
    //void setRadians() {
    //    setRadiansZero();
    //    setRadiansPi();
    //    setRadiansNegativePi();
    //    setRadiansSevenPi();
    //}
    //void setDegrees() {
    //    setDegreesZero();
    //    setDegrees180();
    //    setDegreesNegative180();
    //    setDegrees9000();
    //}
};