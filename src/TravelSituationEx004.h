#pragma once

#include "Traveler.h"
#include "TravelSituation.h"
#include "CarSpawner.h"
#include "Road.h"
#include "LaneOfTravel.h"
#include "LaneSegment.h"
#include "Point.h"

using std::make_shared;
using std::shared_ptr;
using std::initializer_list;

class TravelSituationEx004 :
		public TravelSituation
{
public:
	virtual ~TravelSituationEx004() { };

	static shared_ptr<TravelSituation> getInstance();
	virtual std::string getTravelSituationName() override { return "Example 0.004"; };
};

shared_ptr<TravelSituation> TravelSituationEx004::getInstance()
{
	shared_ptr<TravelSituation> situation = std::make_unique<TravelSituationEx004>();

	auto l1s1 = make_shared<LaneSegment>(XYPoint(0,0), XYPoint(10,10), 2);
	auto spawn1 = make_shared<CarSpawner>(0.5, l1s1, situation);
	situation->addTickable(spawn1);
	auto l1 = make_shared<LaneOfTravel>(initializer_list<shared_ptr<LaneSegment>>( {l1s1} ));
	auto r1 = make_shared<Road>(initializer_list<shared_ptr<LaneOfTravel>>({l1}));

	situation->addRoad(r1);

	return situation;
}
