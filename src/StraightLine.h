#pragma once

#include <iostream> //TODO

#include <memory>
#include <cmath>
#include <chrono>

#include "Point.h"

using std::shared_ptr;
using std::chrono::milliseconds;

struct MXBLine
{
	double m{};
	double b{};

	MXBLine() {};
	MXBLine(double m, double b): m(m), b(b) {};
};

class StraightLine
{
private :
	XYPoint start{};
	XYPoint end{};

public :
	StraightLine() {};
	StraightLine(XYPoint start, XYPoint end): start(start), end(end) {};

	static bool hasCollision(StraightLine s1, StraightLine s2);
	static XYPoint findIntersection(MXBLine l1, MXBLine l2);

	MXBLine getYMXBLine();
	MXBLine getXMTBLine();
	milliseconds getTimeOfX(double x);
	bool containsTime(milliseconds t);
};
