#include "Traveler.h"

bool operator==(const Traveler& lhs, const Traveler& rhs)
{
	return lhs.getId() == rhs.getId();
}

void Traveler::travel()
{
	//TODO introduce passing current time, so that it can be recorded in the position
	lastPosition.x = myPosition.x;
	lastPosition.y = myPosition.y;

	double movedX, movedY;
	movedX = cos(myMovement.direction*Point::PI) * myMovement.speed;
	movedY = sin(myMovement.direction*Point::PI) * myMovement.speed;
	myPosition.x += movedX;
	myPosition.y += movedY;
}

void Traveler::draw(AsciiConsoleOutput* output)
{
	int drawnX = (int)myPosition.x;
	int drawnY = (int)myPosition.y;

	output->setChar(drawnX, drawnY, this->getAsciiChar());
}
