#include <iostream>

#include "Road.h"

Road::Road(initializer_list<shared_ptr<LaneOfTravel>> lanes)
{
	for (shared_ptr<LaneOfTravel> lane : lanes) {
		this->lanes.push_back(lane);
		lane->setRoad(this);
	}
}

Road::~Road() {

}

void Road::draw(AsciiConsoleOutput* output)
{
	for (shared_ptr<LaneOfTravel> lane : lanes) {
		lane->draw(output);
	}
}
