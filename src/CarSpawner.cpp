#include "CarSpawner.h"

Traveler* CarSpawner::getNewTraveler()
{
	return new Car();
}
