#include <iostream>
#include <chrono>
#include <thread>

#include "SimulationTimer.h"
#include "Road.h"
#include "AsciiConsoleOutput.h"

using namespace std;

/*
	The purpose of the main class is to invoke out little checkpoints along the way...
*/

//Example 0.001
// This is ideally what will be getting printed... somehow
int oneLaneRoadTest() {
	for (int k = 0; k < 100; k += 1) {
		cout << "====================================================================================================\n";
		for (int j = 0; j < 100; j += 1) {
			if (j == k)
				cout << "+";
			else
				cout << " ";
		}
		cout << "\n====================================================================================================\n";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	return 0;
}

//Example 0.002
// The goal here is to get the ASCII output looking okay-ish / working at all
int oneLaneRoad() {
	AsciiConsoleOutput output{};
	Road r{};
	SimulationTimer timer{};

	//timer.addTickable(&r);
	
	//We are not running the timer so that we can call the drawing each frame. TODO refactor into timer?
	//timer.runSimulation();

	while (!timer.isFinished()) {
		output.clearFrame();
		timer.clockTick();
		r.draw(&output);
		output.outputFrame();
	}

	return 0;
}

int main()
{
	//Example 0.001
	//return oneLaneRoadTest();
	
	//Example 0.002
	return oneLaneRoad();
}