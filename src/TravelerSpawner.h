#pragma once
#include <cstdlib>
#include <chrono>

#include "Traveler.h"
#include "LaneOfTravel.h"
#include "TravelSituation.h"

class LaneOfTravel;
class TravelSituation;

class TravelerSpawner :
		public Tickable
{
protected:
	double spawnProbability{};
	shared_ptr<LaneSegment> targetLane{ nullptr };
	shared_ptr<TravelSituation> situation{ nullptr };

	TravelerSpawner(); //50% spawn probability
	TravelerSpawner(double spawnProbability, shared_ptr<LaneSegment> targetLane, shared_ptr<TravelSituation> situation);

public:
	virtual ~TravelerSpawner() { };
	shared_ptr<Traveler> spawn();
	virtual shared_ptr<Traveler> getNewTraveler() = 0;
	virtual void receiveTick() override;
};
