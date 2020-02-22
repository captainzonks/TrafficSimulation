#include <iostream>

#include "Road.h"

Road::Road(size_t startX, size_t startY, size_t endX, size_t endY, initializer_list<LaneOfTravel*> lanes)
{
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;

	for (LaneOfTravel* lane : lanes) {
		this->lanes.push_back(lane);
		lane->setRoad(this);
	}
}

Road::~Road() {

}

void Road::receiveTick() {
}

void Road::draw(AsciiConsoleOutput* output)
{
	for (LaneOfTravel* lane : lanes) {
		lane->draw(output);
	}
}
