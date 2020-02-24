#pragma once

#include "Tickable.h"

#include <vector>
#include <chrono>
#include <thread>

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

	void addTickable(shared_ptr<Tickable> tickable);
	void addTickables(vector<shared_ptr<Tickable>> tickables);
	
	bool isFinished();

private:
	//The list of things that receive ticks
	vector<shared_ptr<Tickable>> tickables{};

	int simulationLastTick{}; //The ticks start at 0, and go until currentTick == simulationLastTick
	int ticksPerSecond{};
	
	int currentTick{};
	milliseconds lastTick{};

};

