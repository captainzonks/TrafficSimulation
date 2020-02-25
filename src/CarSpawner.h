#pragma once

#include "TravelerSpawner.h"
#include "Car.h"

class CarSpawner : //This way we can give the car some random properties, like speed.
	public TravelerSpawner
{
public:
	virtual shared_ptr<Traveler> getNewTraveler() override;
	CarSpawner(double spawnProbability, shared_ptr<LaneSegment> targetLane, shared_ptr<TravelSituation> situation) :
		TravelerSpawner(spawnProbability, targetLane, situation) { };
	virtual ~CarSpawner() { };

};
