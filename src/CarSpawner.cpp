#include "CarSpawner.h"

shared_ptr<Traveler> CarSpawner::getNewTraveler()
{
	shared_ptr<Traveler> car = make_shared<Car>();
	car->getMovement()->direction = targetLane->getDirection();
	car->getMovement()->speed = targetLane->getSpeedLimit();
	car->getPosition()->x = targetLane->getStartPoint().x;
	car->getPosition()->y = targetLane->getStartPoint().y;
	return car;
}
