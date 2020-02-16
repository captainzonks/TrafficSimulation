#include <iostream>

#include "Road.h"

Road::Road()
{
	northSouth = false;
	constantAxisPosition = 3;
}

Road::Road(bool northSouth, size_t constantAxisPosition)
{
	this->northSouth = northSouth;
	this->constantAxisPosition = constantAxisPosition;
}

void Road::receiveTick() {
}

void Road::draw(AsciiConsoleOutput* output)
{
	if (northSouth) {
		for (size_t k = 0; k < output->max_y; k += 1) { //TODO get the dimension max from the AsciiConsoleOutput
			output->setChar(constantAxisPosition, k, '|');
		}
	}
	else {
		for (size_t k = 0; k < output->max_x; k += 1) { //TODO get the dimension max from the AsciiConsoleOutput
			output->setChar(k, constantAxisPosition, '-');
		}
	}
}
