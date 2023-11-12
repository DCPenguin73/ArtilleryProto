/***********************************************************************
* Header File :
*Test Database : Test the Database class
* Author :
    *Daniel Carr
    * Summary :
    *All the unit tests for Database
    ************************************************************************/


#pragma once

#include <iostream>
#include "database.h"
#include <cassert>

    using namespace std;

/*******************************
 * TEST Database
 * A friend class for Database which contains the Database unit tests
 ********************************/
class TestDatabase
{
public:
    void run()
    {
        defaultConstructor();
        linerInter();
        searchDatabase();
    }
private:
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }
    void defaultConstructor() const
    {  // setup
        double domain[] = { 3.0 };
        double range[] = { .5 };
       // exercise
        Database data = Database( domain,  range, 1);
        // verify
        assert(data.domain[0] == 3.0);
        assert(data.range[0] == 0.5);
        assert(data.length == 1);
    }  // teardown
    void linerInter() {
        linerOut();
    }
    void searchDatabase() {
        searchInbound();
        searchOutbound();
        searchNegative();
    }
    void linerOut() {
        // setup
        double domain[] = { 1, 2, 3, 4, 5 };
        double range[] = { .1, .2, .3, .4, .5 };
        Database data = Database(domain, range, 5);
        double x1 = 1;
        double x2 = 2;
        double y1 = 2;
        double y2 = 4;
        double p = 1.5;
        //exercise
        double value = data.linearInter(x1, y1, x2, y2, p);
        // verify
        assert(closeEnough(value, 3, 0.0000001));
    }
    void searchInbound() {
        // setup
        double domain[] = { 1, 2, 3, 4, 5 };
        double range[] = { .1, .2, .3, .4, .5 };
        Database data = Database(domain, range, 5);
        //exercise
        double value = data.searchDatabase(3);
        //verify
        assert(closeEnough(value, .3, .000001));
    }
    void searchOutbound() {
        // setup
        double domain[] = { 1, 2, 3, 4, 5 };
        double range[] = { .1, .2, .3, .4, .5 };
        Database data = Database(domain, range, 5);
        //exercise
        double value = data.searchDatabase(6);
        //verify
        assert(value == NULL);
    }
    void searchNegative() {
        // setup
        double domain[] = { 1, 2, 3, 4, 5 };
        double range[] = { .1, .2, .3, .4, .5 };
        Database data = Database(domain, range, 5);
        //exercise
        double value = data.searchDatabase(-1);
        //verify
        assert(closeEnough(value, -.1, .000001));
    }
};