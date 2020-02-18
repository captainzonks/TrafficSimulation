#pragma once
#include "Traveler.h"
#include "Tickable.h"
/*
 * Cars travel in the LaneOfTravel in a road
 */
class Car :
	virtual public Traveler, public Tickable
{
private:

public:
    void receiveTick(); //is this shadowing Tickable's function?
    char getAsciiChar();
};

