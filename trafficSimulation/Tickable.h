#pragma once


class Tickable
{
public:

	virtual void receiveTick() = 0; //this makes it a pure virtual so child classes must implement the method

private:


};

