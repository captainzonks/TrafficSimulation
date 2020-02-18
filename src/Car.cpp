#include <iostream>
#include "Car.h"

void Car::receiveTick() {
	//The car needs to move in the direction
	travel();
}

char Car::getAsciiChar()
{
	return 'c';
}
