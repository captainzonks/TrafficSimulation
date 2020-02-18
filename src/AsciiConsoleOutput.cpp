#include <iostream>
#include "AsciiConsoleOutput.h"

#include <sstream>

void AsciiConsoleOutput::setChar(size_t x, size_t y, char c) {
	if (x < 0 || x >= max_x)
		return;
	if (y < 0 || y >= max_y)
		return;
	
	this->outputMap[y][x] = c;
}

void AsciiConsoleOutput::outputFrame() {
	std::stringstream ss;
	ss << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
			<< "============================================================================\n"; //Poor man's clear console
	for (size_t y = 0; y < max_y; y += 1) {
		for (size_t x = 0; x < max_x; x += 1) {
			ss << this->outputMap[y][x];
		}
		ss << "\n";
	}
	std::cout << ss.str();
}

void AsciiConsoleOutput::clearFrame() {
	for (size_t y = 0; y < max_y; y += 1)
		for (size_t x = 0; x < max_x; x += 1)
			this->outputMap[y][x] = ' ';
}