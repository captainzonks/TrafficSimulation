#pragma once

#include "TravelerSpawner.h"
#include "Car.h"

class CarSpawner : //This way we can give the car some random properties, like speed.
	public TravelerSpawner
{
public:
	virtual Traveler* getNewTraveler() override;
	CarSpawner(double spawnProbability, LaneSegment* targetLane) :
		TravelerSpawner(spawnProbability, targetLane) { };
	virtual ~CarSpawner() { };

};
