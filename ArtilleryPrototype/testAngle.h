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
        
        convertToDegrees();
        convertToRadians();
        normalize();
        //getRadians();
        //getDegrees();
        //setRadians();
        //setDegrees();
    }

private:
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }
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
            assert(closeEnough(angle.radians, TWO_PI/2, .000000000001));
        }  // teardown
    void convertToDegrees(){
        convertToDegreesZero();
        convertToDegreesPi();
    }
    void convertToRadians() {
        convertToRadiansZero();
        convertToRadians180();
    }
    void normalize() {
        normalizeNoChange();
        normalizeNegativePi();
        normalizeSevenPi();
    }
    void getRadians() {
        getRadiansZero();
        getRadiansPi();
    }
    void getDegrees() {
        getDegreesZero();
        getDegrees180();
    }
    void setRadians() {
        setRadiansZero();
        setRadiansPi();
        setRadiansNegativePi();
        setRadiansSevenPi();
    }
    void setDegrees() {
        setDegreesZero();
        setDegrees180();
        setDegreesNegative180();
        setDegrees9000();
    }
    void convertToDegreesZero() {
        // setup
        Angle angle;
        // exercise
        double num = angle.convertToDegrees(0);
        // verify
        assert(num == 0);
    }  // teardown

    void convertToDegreesPi() {
        // setup
        Angle angle;
        // exercise
        double num = angle.convertToDegrees(TWO_PI/2);
        // verify
        assert(closeEnough(num, 180, .00000000001));
    }  // teardown



    void convertToRadiansZero() {
        // setup
        Angle angle;
        // exercise
        double num = angle.convertToRadians(0);
        // verify
        assert(num == 0);
    }  // teardown

    void convertToRadians180() {
        // setup
        Angle angle;
         // exercise
        double num = angle.convertToRadians(180);
        // verify
        assert(closeEnough(num, TWO_PI/2, .00000000001));
    }  // teardown

    void normalizeNoChange() {
        //setup
        Angle angle;
        //exercise
        double num = angle.normalize(TWO_PI);
        //vertify
        assert(closeEnough(num, TWO_PI, .00000000001));
    } //teardown

    void normalizeNegativePi() {
        //setup
        Angle angle;
        //exercise
        double num = angle.normalize(-TWO_PI/2);
        //vertify
        assert(closeEnough(num, TWO_PI/2, .00000000001));
    } //teardown

    void normalizeSevenPi() {
        //setup
        Angle angle;
        //exercise
        double num = angle.normalize(TWO_PI * 3.5);
        //vertify
        assert(closeEnough(num, TWO_PI/2, .00000000001));
    } //teardown

    void getRadiansZero() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        double num = angle.getRadians();
        //vertify
        assert(closeEnough(num, 0, .00000000001));
        } //teardown
    void getRadiansPi() {
        //setup
        Angle angle;
        angle.radians = TWO_PI/2;
        //exercise
        double num = angle.getRadians();
        //vertify
        assert(closeEnough(num, TWO_PI/2, .00000000001));
    } //teardown

    void getDegreesZero() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        double num = angle.getDegrees();
        //vertify
        assert(closeEnough(num, 0, .00000000001));
    } //teardown

    void getDegrees180() {
        //setup
        Angle angle;
        angle.radians = TWO_PI/2;
        //exercise
        double num = angle.getDegrees();
        //vertify
        assert(closeEnough(num, 180, .00000000001));
    } //teardown

    void setRadiansZero() {
        //setup
        Angle angle;
        angle.radians = 1;
        //exercise
        angle.setRadians(0);
        //vertify
        assert(closeEnough(angle.radians, 0, .00000000001));
    } //teardown

    void setRadiansPi() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        angle.setRadians(TWO_PI/2);
        //vertify
        assert(closeEnough(angle.radians, TWO_PI/2, .00000000001));
    } //teardown

    void setRadiansNegativePi() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        angle.setRadians(-TWO_PI/2);
        //vertify
        assert(closeEnough(angle.radians, TWO_PI/2, .00000000001));
    } //teardown

    void setRadiansSevenPi() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        angle.setRadians(TWO_PI*3.5);
        //vertify
        assert(closeEnough(angle.radians, TWO_PI/2, .00000000001));
    } //teardown

    void setDegreesZero() {
        //setup
        Angle angle;
        angle.radians = 1;
        //exercise
        angle.setDegrees(0);
        //vertify
        assert(closeEnough(angle.radians, 0, .00000000001));
    } //teardown
    void setDegrees180() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        angle.setDegrees(180);
        //vertify
        assert(closeEnough(angle.radians, TWO_PI/2, .00000000001));
    } //teardown
    void setDegreesNegative180() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        angle.setDegrees(-180);
        //vertify
        assert(closeEnough(angle.radians, TWO_PI / 2, .00000000001));
    } //teardown
    void setDegrees9000() {
        //setup
        Angle angle;
        angle.radians = 0;
        //exercise
        angle.setDegrees(9000);
        //vertify
        assert(closeEnough(angle.radians, (25*TWO_PI) / 360, .00000000001));
    } //teardown
};