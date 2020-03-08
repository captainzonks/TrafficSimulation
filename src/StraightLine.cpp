#include "StraightLine.h"

//Static method to check if two lines have an intersection on the right time
bool StraightLine::hasCollision(StraightLine s1, StraightLine s2)
{
	//Step 1, find the intersection of the lines
	XYPoint intersection = findIntersection(s1.getYMXBLine(), s2.getYMXBLine());
	if(intersection.x == INFINITY)
		return false; //TODO check intersecting everywhere

	return  s1.containsTime(s1.getTimeOfX(intersection.x)) &&
			s2.containsTime(s2.getTimeOfX(intersection.x));
}

XYPoint StraightLine::findIntersection(MXBLine l1, MXBLine l2)
{
	if(l1.m == l2.m) //parallel
		return XYPoint(INFINITY, INFINITY); //could intersect everywhere

	if(l1.m == INFINITY) { //vertical line
		return XYPoint(l2.m * l1.b + l2.b, l1.b);
	} else if(l2.m == INFINITY) { //vertical line
		return XYPoint(l1.m * l2.b + l1.b, l2.b);
	} else {
		double bTerms = -(l1.b - l2.b);
		double mTerms = l1.m - l2.m;
		double intersectingX = bTerms / mTerms;
		double intersectingY = l1.m * intersectingX + l1.b;
		std::cout << "Intersection found at: " << intersectingX << ", " << intersectingY <<"\n";
		return XYPoint(intersectingX, intersectingY);
	}
}

MXBLine StraightLine::getYMXBLine()
{
	if(start.x == end.x)
		return MXBLine(INFINITY, start.x);

	XYPoint s, e;
	if(start.x < end.x) {
		s = start;
		e = end;
	} else {
		s = end;
		e = start;
	}

	double rise = s.y - e.y;
	double run = s.x - e.x;
	double slope = rise/run;
	double offset = s.y - slope*s.x;

	std::cout << "Found YMXB line: " << slope << "*x + " << offset << "\n";
	return MXBLine(slope, offset);
}

MXBLine StraightLine::getXMTBLine()
{
	if(start.t.count() == -1 || end.t.count() == -1)
		return MXBLine(INFINITY, 0); //TODO better handling

	double xChange = end.x - start.x;
	milliseconds tChange = end.t - start.t;
	double slope = xChange / tChange.count();
	double offset = start.x - slope*start.t.count();

	std::cout << "Found XMTB line: " << slope << "*x + " << offset << "\n";
	return MXBLine(slope, offset);
}

//Assume that X is on the line, just solve for T. Make private for assumption safety?
milliseconds StraightLine::getTimeOfX(double x) {
	if(start.t.count() == -1 || end.t.count() == -1)
		return milliseconds(-1);

	MXBLine xtLine = getXMTBLine();
	unsigned long t = (x-xtLine.b)/xtLine.m;
	return milliseconds(t);
}

bool StraightLine::containsTime(milliseconds t) {
	if(start.t <= t && t <= end.t)
		return true;
	return false;
}
