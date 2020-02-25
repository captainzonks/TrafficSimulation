#include "TravelSituation.h"

void TravelSituation::draw(AsciiConsoleOutput* output)
{
	for(shared_ptr<Road> r : roads)
		r->draw(output);
}

void TravelSituation::addRoad(shared_ptr<Road> road)
{
	roads.push_back(road);
}

void TravelSituation::addTraveler(shared_ptr<Traveler> traveler)
{
	tickables.push_back(traveler);
}

void TravelSituation::addTickable(shared_ptr<Tickable> tickable)
{
	tickables.push_back(tickable);
}
