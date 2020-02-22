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
	size_t startX{};
	size_t startY{};
	size_t endX{};
	size_t endY{};
	std::vector<LaneOfTravel> lanes;

public :
	Road(size_t startX, size_t startY, size_t endX, size_t endY, initializer_list<LaneOfTravel*> lanes);

	void receiveTick();
	void draw(AsciiConsoleOutput* output);

	size_t getStartX() { return startX; };
	size_t getStartY() { return startY; };
	size_t getEndX() { return endX; };
	size_t getEndY() { return endY; };
};

