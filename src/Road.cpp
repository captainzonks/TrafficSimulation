#include <iostream>

#include "Road.h"

Road::Road()
{
	northSouth = false;
	constantAxisPosition = 3;
}

Road::Road(bool northSouth, size_t constantAxisPosition, initializer_list<LaneOfTravel*> lanes)
{
	this->northSouth = northSouth;
	this->constantAxisPosition = constantAxisPosition;

	for (LaneOfTravel* lane : lanes) {
		this->lanes.push_back(*lane);
		lane->setRoad(this);
	}
}

void Road::receiveTick() {
}

void Road::draw(AsciiConsoleOutput* output)
{
	if (northSouth) {
		for (size_t k = 0; k < output->max_y; k += 1) { //TODO get the dimension max from the AsciiConsoleOutput
			output->setChar(constantAxisPosition, k, '|');
		}
	}
	else {
		for (size_t k = 0; k < output->max_x; k += 1) { //TODO get the dimension max from the AsciiConsoleOutput
			output->setChar(k, constantAxisPosition, '-');
		}
	}

	for (LaneOfTravel lane : lanes) {
		lane.draw(output);
	}
}
