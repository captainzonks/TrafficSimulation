#include "LaneOfTravel.h"

/*
* A lane of travel is a container connecting lane segments
*/

LaneOfTravel::LaneOfTravel()
{
	this->laneSegments.clear();
}

LaneOfTravel::LaneOfTravel(initializer_list<shared_ptr<LaneSegment>> laneSegments)
{
	for(shared_ptr<LaneSegment> ls : laneSegments) {
		this->laneSegments.push_back(ls);
		ls->setLaneOfTravel(this);
	}
}

LaneOfTravel::~LaneOfTravel()
{
	laneSegments.clear();
}

void LaneOfTravel::draw(AsciiConsoleOutput* output)
{
	for(shared_ptr<LaneSegment> ls : laneSegments)
		ls->draw(output);
}
