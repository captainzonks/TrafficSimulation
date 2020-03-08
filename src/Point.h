#pragma once

#include "Traveler.h" //TODO get PI from somewhere better
#include <cmath>
#include <chrono>

using std::chrono::milliseconds;

struct XYPoint {
	double x{};
	double y{};
	milliseconds t{};

	XYPoint() { }
	XYPoint(double x, double y): x(x), y(y), t(milliseconds(-1)) { };
	XYPoint(double x, double y, milliseconds t): x(x), y(y), t(t) {};
	XYPoint(double x, double y, long t): x(x), y(y), t(milliseconds(t)) {};
};

class Point {
public:
	//provide static functions for XY point comparison
	static double getDistanceBetween(XYPoint p1, XYPoint p2);
	static double getDirection(XYPoint p1, XYPoint p2); //From p1 to p2, in radians
};
