#pragma once
#include "Tickable.h"
#include "Drawable.h"
#include "LaneOfTravel.h"
#include "AsciiConsoleOutput.h"

#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;
using std::initializer_list;

class LaneOfTravel; //forward declaration for LaneOfTravel

class Road :
	public Drawable
{
private:
	vector<shared_ptr<LaneOfTravel>> lanes;

public :
	Road(initializer_list<shared_ptr<LaneOfTravel>> lanes);
	virtual ~Road();

	void draw(AsciiConsoleOutput* output);
};

