#pragma once

#include <vector>

#include "Drawable.h"
#include "LaneOfTravel.h"
#include "AsciiConsoleOutput.h"
#include "Traveler.h"
#include "Point.h"

class LaneOfTravel;

using std::vector;

//A LaneSegment is, for now at least, a straight segment of road with a single speed limit and no intersections
class LaneSegment :
	public Drawable
{
private :
	double direction{};
	double length{};
	double speedLimit{};

	XYPoint startPoint{};
	XYPoint endPoint{};

	LaneOfTravel* laneOfTravel = nullptr;
	int segmentIndex{};
	vector<Traveler*> travelersInSegment{};

public:
	LaneSegment(XYPoint startPoint, XYPoint endPoint, double speedLimit); //TODO add expected traveler type?
	virtual ~LaneSegment();

	//Getters
	double getDirection() { return direction; };
	double getLength() { return length; };
	double getSpeedLimit() { return speedLimit; };

	void setLaneOfTravel(LaneOfTravel* laneOfTravel) { this->laneOfTravel = laneOfTravel; };
	void setSegmentIndex(int segementIndex) { this->segmentIndex = segmentIndex; };
	int getSegmentIndex() { return segmentIndex; };

	void addTraveler(Traveler* traveler);
	void removeTraveler(Traveler* traveler);

	virtual void draw(AsciiConsoleOutput* output) override;
};
