#pragma once
#include "Traveler.h"
#include "Tickable.h"
/*
 * Cars travel in the LaneOfTravel in a road
 */
class Car :
	public Traveler, public Tickable
{
private:
    double x{};
    double y{};
public:
    void receiveTick(); //is this shadowing Tickable's function?
    int main();
};

