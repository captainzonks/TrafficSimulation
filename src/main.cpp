#include <iostream>
#include <chrono>
#include <thread>

#include "SimulationTimer.h"
#include "Road.h"
#include "AsciiConsoleOutput.h"
#include "Car.h"

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
// Also get get a car and an agressing car to hit each other in the lane
int oneLaneRoad() {
	//things are going to take place at x position = 3 for this example
	size_t xPosition = 3;

	AsciiConsoleOutput output{};
	LaneOfTravel southbound{};
	
	//Let's create a car to send down the lane...
	Car car{};
	//The car needs to be in the right position...
	car.getPosition()->x = (double)xPosition; //y is already 0
	car.getMovement()->speed = 1; //for the ASCII prints this is one char per tick
	car.getMovement()->direction = 0;

	//Hack out a second car on a collision course...
	Car aggressingCar{};
	aggressingCar.getPosition()->x = (double)xPosition; //y is already 0
	aggressingCar.getPosition()->y = 25; //stolen from current constant in ASCII
	aggressingCar.getMovement()->speed = 2;
	aggressingCar.getMovement()->direction = 1;

	southbound.addTraveler(&car);
	southbound.addTraveler(&aggressingCar);
	
	//Let's put the lane in a road
	Road r{ true, xPosition, { &southbound } };

	SimulationTimer timer{10, 1};

	//timer.addTickable(&r);
	timer.addTickable(&car);
	timer.addTickable(&aggressingCar);

	//We are not running the timer so that we can call the drawing each frame. TODO refactor into timer?
	//timer.runSimulation();
	output.clearFrame();
	output.outputFrame();

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