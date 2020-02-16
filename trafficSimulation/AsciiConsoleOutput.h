#pragma once
#include <iostream>
//TODO dynamic size?
class AsciiConsoleOutput
{
private:
	char outputMap[25][25]{};
public:
	//methods
	void setChar(size_t x, size_t y, char c);
	void outputFrame();
	void clearFrame();

	//variables
	const size_t max_x = 25;
	const size_t max_y = 25;
};

