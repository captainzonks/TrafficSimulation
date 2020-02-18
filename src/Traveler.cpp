#include "Traveler.h"

#define PI 3.14159265 //TODO get this value from a library?

bool operator==(const Traveler& lhs, const Traveler& rhs)
{
	return lhs.id == rhs.id;
}

void Traveler::travel()
{
	double movedX, movedY;
	movedX = sin(myMovement.direction*PI) * myMovement.speed;
	movedY = cos(myMovement.direction*PI) * myMovement.speed;
	myPosition.x += movedX;
	myPosition.y += movedY;
}

void Traveler::draw(AsciiConsoleOutput* output)
{
	int drawnX = (int)myPosition.x;
	int drawnY = (int)myPosition.y;

	output->setChar(drawnX, drawnY, this->getAsciiChar());
}
