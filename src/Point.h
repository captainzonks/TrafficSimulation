#pragma once

#include "Traveler.h" //TODO get PI from somewhere better
#include <cmath>

struct XYPoint {
	double x{};
	double y{};

	XYPoint() { }
	XYPoint(double x, double y): x(x), y(y) { }
};

class Point {
public:
	//provide static functions for XY point comparison
	static double getDistanceBetween(XYPoint p1, XYPoint p2);
	static double getDirection(XYPoint p1, XYPoint p2); //From p1 to p2, in radians
};
