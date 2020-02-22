#pragma once
#include "Traveler.h"
#include "Tickable.h"
/*
 * Cars travel in the LaneOfTravel in a road
 */
class Car :
	virtual public Traveler
{
private:

public:
    virtual void receiveTick() override; //is this shadowing Tickable's function?
    char getAsciiChar();
};

