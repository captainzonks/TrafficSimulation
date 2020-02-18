#pragma once
#include "Tickable.h"
#include "Drawable.h"
#include "LaneOfTravel.h"
#include "AsciiConsoleOutput.h"

#include<vector>
#include<stdarg.h>

using std::initializer_list;

class LaneOfTravel; //forward declaration for LaneOfTravel

class Road :
	public Tickable, public Drawable
{
private:
	bool northSouth{};
	size_t constantAxisPosition{};
public :
	Road();
	Road(bool northSouth, size_t constantAxisPosition, initializer_list<LaneOfTravel*> lanes);

	std::vector<LaneOfTravel> lanes;
	void receiveTick();
	void draw(AsciiConsoleOutput* output);
};

