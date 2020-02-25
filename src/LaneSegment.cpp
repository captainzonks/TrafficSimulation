#include "LaneSegment.h"

LaneSegment::LaneSegment(XYPoint startPoint, XYPoint endPoint, double speedLimit)
{
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->direction = Point::getDirection(startPoint, endPoint);
	this->length = Point::getDistanceBetween(startPoint, endPoint);
	this->speedLimit = speedLimit;
}

LaneSegment::~LaneSegment()
{

}

void LaneSegment::addTraveler(shared_ptr<Traveler> traveler)
{
	travelersInSegment.push_back(traveler);
}

void LaneSegment::removeTraveler(shared_ptr<Traveler> traveler)
{
	for (auto it = begin(travelersInSegment); it != end(travelersInSegment); ++it) {
		if (*it == traveler) {
			travelersInSegment.erase(it);
			return;
		}
	}
}

void LaneSegment::draw(AsciiConsoleOutput* output)
{
	double incrementX = sin(direction * Traveler::PI);
	double incrementY = cos(direction * Traveler::PI);

	double xPos = startPoint.x;
	double yPos = startPoint.y;

	//TODO get a character for the direction of the road
	while (xPos < endPoint.x && yPos < endPoint.y) {
		output->setChar((size_t)xPos, (size_t)yPos, '-');
		xPos += incrementX;
		yPos += incrementY;
	}

	for (auto it = begin(travelersInSegment); it != end(travelersInSegment); ++it) {
		(*it)->draw(output);
	}
}
