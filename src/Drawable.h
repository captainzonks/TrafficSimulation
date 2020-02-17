#pragma once
#include "AsciiConsoleOutput.h"

class Drawable
{
public:
	virtual void draw(AsciiConsoleOutput *output) = 0;
};

