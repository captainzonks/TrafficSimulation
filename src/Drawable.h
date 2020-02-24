#pragma once
#include "AsciiConsoleOutput.h"

class Drawable
{
public:
	virtual ~Drawable() { };
	virtual void draw(AsciiConsoleOutput *output) = 0;
};

