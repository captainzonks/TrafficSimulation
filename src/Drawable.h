#pragma once
#include "AsciiConsoleOutput.h"

class Drawable
{
public:
	virtual ~Drawable() { };

	//TODO convert to unique_ptr
	virtual void draw(AsciiConsoleOutput *output) = 0;
};

