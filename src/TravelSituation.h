#pragma once

#include <cstdlib>
#include <vector>
#include <memory>

#include "Traveler.h"
#include "Tickable.h"
#include "Road.h"

using std::vector;
using std::string;
using std::shared_ptr;

class TravelSituation :
		public Drawable
{
protected:
	vector<shared_ptr<Tickable>> tickables{};
	vector<shared_ptr<Road>> roads{};

public:
	virtual ~TravelSituation() { };

	vector<shared_ptr<Tickable>> getTickables() { return tickables; };
	virtual string getTravelSituationName() = 0;
	void addRoad(shared_ptr<Road> road);

	virtual void draw(AsciiConsoleOutput* output) override;

};
