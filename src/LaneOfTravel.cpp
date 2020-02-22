#include "LaneOfTravel.h"

/*
* A lane of travel is what a traveler will consult for 
* other information about things in the lane of travel
*/
//LaneOfTravel::LaneOfTravel(Road myRoad) {
//	this->myRoad = myRoad;
//}

LaneOfTravel::LaneOfTravel()
{
	//Going with a north to south for default
	direction = 0;
	speedLimit = 55;
	this->road = nullptr;
	this->spawner = nullptr;
}

LaneOfTravel::LaneOfTravel(double direction, double speedLimit, Road* road, TravelerSpawner* spawner)
{
	this->direction = direction;
	this->speedLimit = speedLimit;
	this->road = road;
	this->spawner = spawner;
	//this->spawner->setTargetLane(this);
}

LaneOfTravel::~LaneOfTravel()
{
	if (spawner != nullptr) {
		delete spawner;
		spawner = nullptr;
	}

	for (Traveler* traveler : travelersInLane)
		delete traveler;

	travelersInLane.clear();
}

void LaneOfTravel::receiveTick()
{
	for (Traveler* traveler : travelersInLane) {
		traveler->receiveTick();
	}

	if (spawner != nullptr) {
		Traveler* newTraveler = spawner->spawn();
		if (newTraveler != nullptr) {
			this->addTraveler(newTraveler);
		}
	}
}

void LaneOfTravel::addTraveler(Traveler* traveler)
{
	travelersInLane.push_back(traveler);
}

void LaneOfTravel::removeTraveler(Traveler* traveler)
{
	for (auto it = begin(travelersInLane); it != end(travelersInLane); ++it) {
		if (*it == traveler) {
			travelersInLane.erase(it);
			return;
		}
	}
}

void LaneOfTravel::draw(AsciiConsoleOutput* output)
{
	double incrementX = sin(direction * Traveler::PI);
	double incrementY = cos(direction * Traveler::PI);

	double xPos = (double)road->getStartX();
	double yPos = (double)road->getStartY();
	double endXPos = (double)road->getEndX();
	double endYPos = (double)road->getEndY();
	while (xPos < endXPos && yPos < endYPos) {
		output->setChar((size_t)xPos, (size_t)yPos, 'F');
		xPos += incrementX;
		yPos += incrementY;
	}

	for (auto it = begin(travelersInLane); it != end(travelersInLane); ++it) {
		(*it)->draw(output);
	}
}
