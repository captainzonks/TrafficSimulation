#pragma once
#include "Tickable.h"
#include "Road.h"
#include "Traveler.h"
#include "TravelerSpawner.h"

#include <vector>


using std::vector;

class Road; //Forward declare the road.
class TravelerSpawner;

class LaneOfTravel :
	public Drawable, public Tickable
{
private:
	Road* road{ nullptr };
	vector<Traveler*> travelersInLane{};
	double direction{};
	double speedLimit{};
	TravelerSpawner* spawner{ nullptr };

public:
	LaneOfTravel();
	LaneOfTravel(double direction, double speedLimit, Road* road, TravelerSpawner* spawner);
	~LaneOfTravel();

	//Getters
	double getDirection() { return direction; };
	double getSpeedLimit() { return speedLimit; }

	void setRoad(Road* road) { this->road = road; };
	virtual void receiveTick() override;

	//For management of cars in the lane
	void addTraveler(Traveler* traveler);
	void removeTraveler(Traveler* traveler);

	//Lanes of travels draw by invoking the draw function on the travelers (for now)
	void draw(AsciiConsoleOutput* output);
};

