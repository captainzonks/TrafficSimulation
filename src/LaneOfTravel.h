#pragma once
#include "Tickable.h"
#include "Road.h"
#include "Traveler.h"

#include <vector>

using std::vector;

class Road; //Forward declare the road.

class LaneOfTravel :
	public Drawable
{
private:
	Road* road = nullptr;
	vector<Traveler*> travelersInLane{};

public:
	void setRoad(Road* road) { this->road = road; };

	//For management of cars in the lane
	void addTraveler(Traveler* traveler);
	void removeTraveler(Traveler* traveler);

	//Lanes of travels draw by invoking the draw function on the travelers (for now)
	void draw(AsciiConsoleOutput* output);
};

