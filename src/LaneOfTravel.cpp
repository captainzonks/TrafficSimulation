#include "LaneOfTravel.h"

/*
* A lane of travel is what a traveler will consult for 
* other information about things in the lane of travel
*/
//LaneOfTravel::LaneOfTravel(Road myRoad) {
//	this->myRoad = myRoad;
//}

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
	for (auto it = begin(travelersInLane); it != end(travelersInLane); ++it) {
		(*it)->draw(output);
	}
}
