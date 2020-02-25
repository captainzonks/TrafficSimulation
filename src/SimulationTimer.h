#pragma once

#include <vector>
#include <chrono>
#include <thread>

#include "Tickable.h"
#include "TickableProvider.h"

using std::chrono::milliseconds;
using std::vector;
using std::shared_ptr;

class SimulationTimer
{
public:
	//Constructors
	SimulationTimer();
	SimulationTimer(const int simulationLastTick, const int ticksPerSecond);

	// methods
	void runSimulation();
	void clockTick();

	void setTickableProvider(shared_ptr<TickableProvider> tickableProvider) { this->tickableProvider = tickableProvider; };
	
	bool isFinished();

private:
	shared_ptr<TickableProvider> tickableProvider;

	int simulationLastTick{}; //The ticks start at 0, and go until currentTick == simulationLastTick
	int ticksPerSecond{};
	
	int currentTick{};
	milliseconds lastTick{};

};

