#pragma once

#include <cmath>
#include <vector>
#include <memory>

#include "Tickable.h"
#include "Road.h"
#include "Traveler.h"
#include "LaneSegment.h"

using std::vector;
using std::initializer_list;
using std::shared_ptr;

class Road; //Forward declare the road.
class LaneSegment;

class LaneOfTravel :
	public Drawable
{
private:
	Road* road{ nullptr };
	vector<shared_ptr<LaneSegment>> laneSegments{};

public:
	LaneOfTravel();
	LaneOfTravel(initializer_list<shared_ptr<LaneSegment>> laneSegments);
	virtual ~LaneOfTravel();

	void setRoad(Road* road) { this->road = road; };

	//For management of cars in the lane
	void addTraveler(Traveler* traveler);
	void removeTraveler(Traveler* traveler);

	//Lanes of travels draw by invoking the draw function on the travelers (for now)
	void draw(AsciiConsoleOutput* output);
};

