#pragma once

#include "Tickable.h"

#include <vector>
#include <chrono>
#include <thread>

using std::chrono::milliseconds;

class SimulationTimer
{
public:
	//Constructors
	SimulationTimer();
	SimulationTimer(const int simulationLastTick, const int ticksPerSecond);

	// methods
	void runSimulation();
	void clockTick();

	void addTickable(Tickable* tickable);
	
	bool isFinished();

private:
	//The list of things that receive ticks
	std::vector<Tickable*> tickables{};

	int simulationLastTick{}; //The ticks start at 0, and go until currentTick == simulationLastTick
	int ticksPerSecond{};
	
	int currentTick{};
	std::chrono::milliseconds lastTick{};

};

