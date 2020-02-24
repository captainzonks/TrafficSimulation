#include "TravelerSpawner.h"

TravelerSpawner::TravelerSpawner()
{
	spawnProbability = 0.5;
	srand((unsigned int)time(NULL));
}

TravelerSpawner::TravelerSpawner(double spawnProbability, LaneSegment* targetLane)
{
	this->spawnProbability = spawnProbability;
	this->targetLane = targetLane;
	srand((unsigned int)time(NULL));
}

Traveler* TravelerSpawner::spawn()
{
	if (((double)rand() / (RAND_MAX)) < spawnProbability)
		return getNewTraveler();
	return nullptr;
}
