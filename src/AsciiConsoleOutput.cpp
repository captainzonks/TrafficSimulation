#include <iostream>
#include "AsciiConsoleOutput.h"

void AsciiConsoleOutput::setChar(size_t x, size_t y, char c) {
	if (x < 0 || x >= max_x)
		return;
	if (y < 0 || y >= max_y)
		return;
		
	std::cout << "setting: " << c << " to " << x << "," << y << '\n';
	this->outputMap[x][y] = c;
}

void AsciiConsoleOutput::outputFrame() {
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; //Poor man's clear console
	for (size_t x = 0; x < max_x; x += 1) {
		for (size_t y = 0; y < max_y; y += 1) {
			std::cout << this->outputMap[x][y];
		}
		std::cout << "\n";
	}
}

void AsciiConsoleOutput::clearFrame() {
	for (size_t x = 0; x < max_x; x += 1)
		for (size_t y = 0; y < max_y; y += 1)
			this->outputMap[x][y] = 'x';
}