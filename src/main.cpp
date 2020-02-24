#include <iostream>
#include <chrono>
#include <thread>

#include "SimulationTimer.h"
#include "AsciiConsoleOutput.h"
#include "TravelSituation.h"

//Specific situations...
#include "TravelSituationEx004.h"

using namespace std;

/*
	The purpose of the main class is to invoke out little checkpoints along the way...
*/

//Example 0.001
// This is ideally what will be getting printed... somehow
/*int oneLaneRoadTest() {
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
}*/

//Example 0.002
// The goal here is to get the ASCII output looking okay-ish / working at all
// Also get get a car and an agressing car to hit each other in the lane

//COMMENTED OUT, the signature for roads and such changes to make more
//arbitrary directions possible.

/*int oneLaneRoad() {
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
}*/

/*int twoLaneRoad() { //Create a road with one lane in each direction
	//By now our lanes should handle car creation in the ticks of time

	//Let's try to make a diagonal road....
	CarSpawner southeastSpawner{};
	CarSpawner northwestSpawner{};
	LaneOfTravel southeast{ 1.75, 30, nullptr, &southeastSpawner };
	LaneOfTravel northwest{ 1.75, 30, nullptr, &northwestSpawner };
	southeastSpawner.setTargetLane(&southeast);
	northwestSpawner.setTargetLane(&northwest);
	Road twoLaneRoad{ 0, 0, 10, 10, { &southeast, &northwest } };

	SimulationTimer timer{ 10, 1 };
	timer.addTickable(&twoLaneRoad);

	AsciiConsoleOutput output{};
	output.clearFrame();
	output.outputFrame();

	while (!timer.isFinished()) {
		output.clearFrame();
		timer.clockTick();
		twoLaneRoad.draw(&output);
		output.outputFrame();
	}

	return 5;
}*/

int travelSituationEx004() {
	auto situation = TravelSituationEx004::getInstance();
	SimulationTimer timer = SimulationTimer{1, 10};

	timer.addTickables(situation->getTickables());
	AsciiConsoleOutput output{};
	output.clearFrame();
	output.outputFrame();

	while (!timer.isFinished()) {
		output.clearFrame();
		timer.clockTick();
		situation->draw(&output);
		output.outputFrame();
	}

	return 0;
}

int main()
{
	//Example 0.001
	//return oneLaneRoadTest();
	
	//Example 0.002
	//return oneLaneRoad();

	//Example 0.003
	//return twoLaneRoad(); //Abandoned for larger ambition

	return travelSituationEx004();


}
