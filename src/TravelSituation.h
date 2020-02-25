#pragma once

#include <cstdlib>
#include <vector>
#include <memory>

#include "TickableProvider.h"
#include "Traveler.h"
#include "Tickable.h"
#include "Road.h"

using std::vector;
using std::string;
using std::shared_ptr;

class TravelSituation :
		public Drawable, public TickableProvider
{
protected:
	vector<shared_ptr<Tickable>> tickables{};
	vector<shared_ptr<Road>> roads{};

public:
	virtual ~TravelSituation() { };

	virtual vector<shared_ptr<Tickable>> getTickables() override { return tickables; };
	virtual string getTravelSituationName() = 0;
	void addRoad(shared_ptr<Road> road);
	void addTraveler(shared_ptr<Traveler> traveler);
	void addTickable(shared_ptr<Tickable> tickable);

	virtual void draw(AsciiConsoleOutput* output) override;

};
