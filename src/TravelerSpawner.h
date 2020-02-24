#pragma once
#include <cstdlib>
#include <chrono>

#include "Traveler.h"
#include "LaneOfTravel.h"

class LaneOfTravel;

class TravelerSpawner
{
protected:
	double spawnProbability{};
	LaneSegment* targetLane{ nullptr };

	TravelerSpawner(); //50% spawn probability
	TravelerSpawner(double spawnProbability, LaneSegment* targetLane);

public:
	virtual ~TravelerSpawner() { };
	Traveler* spawn();
	virtual Traveler* getNewTraveler() = 0;
};
