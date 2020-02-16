#pragma once
#include "Tickable.h"

class Intersection :
	public Tickable
{
public:

	enum LightColor { green, yellow, red };

	LightColor northLight{ green };
	LightColor southLight{ green };
	LightColor westLight{ red };
	LightColor eastLight{ red };

};

