#pragma once

#include <vector>
#include <memory>

#include "Tickable.h"

using std::shared_ptr;
using std::vector;

class TickableProvider
{
public:
	virtual ~TickableProvider() {};
	virtual vector<shared_ptr<Tickable>> getTickables() = 0;
};
