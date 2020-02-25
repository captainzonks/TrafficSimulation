#include "TravelerSpawner.h"

TravelerSpawner::TravelerSpawner()
{
	spawnProbability = 0.5;
	srand((unsigned int)time(NULL));
}

TravelerSpawner::TravelerSpawner(double spawnProbability, shared_ptr<LaneSegment> targetLane, shared_ptr<TravelSituation> situation)
{
	this->spawnProbability = spawnProbability;
	this->targetLane = targetLane;
	this->situation = situation;
	srand((unsigned int)time(NULL));
}

shared_ptr<Traveler> TravelerSpawner::spawn()
{
	if (((double)rand() / (RAND_MAX)) < spawnProbability)
		return getNewTraveler();
	return nullptr;
}

void TravelerSpawner::receiveTick()
{
	shared_ptr<Traveler> newTraveler = spawn();
	if(newTraveler) {
		targetLane->addTraveler(newTraveler);
		situation->addTraveler(newTraveler);
	}
}
