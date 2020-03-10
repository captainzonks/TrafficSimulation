#include "Point.h"

double Point::getDistanceBetween(XYPoint p1, XYPoint p2) {
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

double Point::getDirection(XYPoint p1, XYPoint p2) {
	double x = p2.x-p1.x;
	double y = p2.y-p1.y;

	if(x == 0) {
		if(y >= 0)
			return 0;
		else
			return 1;
	} else if(y == 0) {
		if(x >= 0)
			return 1.5;
		else
			return .5;
	} else
		return atan(y/x)/PI;
}
