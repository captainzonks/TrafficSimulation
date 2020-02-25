#include <iostream>
#include "SimulationTimer.h"

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

SimulationTimer::SimulationTimer() {
	this->simulationLastTick = 1;
	this->ticksPerSecond = 1;
	//Default constructor will only have one tick
}

SimulationTimer::SimulationTimer(const int simulationLastTick, const int ticksPerSecond) {
	this->simulationLastTick = simulationLastTick;
	this->ticksPerSecond = ticksPerSecond;
	this->lastTick = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
}

void SimulationTimer::runSimulation() {
	while (currentTick < simulationLastTick)
		clockTick();
}

void SimulationTimer::clockTick()
{
	//std::cout << "Clocks a tickin";
	milliseconds nextTick = lastTick + milliseconds(1000 / ticksPerSecond);
	for (shared_ptr<Tickable> t : tickableProvider->getTickables())
	{
		t->receiveTick();
	}
	currentTick += 1;
	milliseconds now = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if (nextTick > now) {
		milliseconds sleepMillis = duration_cast<milliseconds>(nextTick - now);
		std::cout << "Sleeping for: " << sleepMillis.count() << "ms";
		std::this_thread::sleep_for(sleepMillis);
	}
	lastTick = nextTick;

}
bool SimulationTimer::isFinished()
{
	return currentTick >= simulationLastTick;
}
