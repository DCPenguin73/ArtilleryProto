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
#include "position.h"
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
    void defaultConstructor() const
    {  // setup
       // exercise
        Database pos;
        // verify
        assert(pos.x == 0.0);
        assert(pos.y == 0.0);
    }  // teardown
};