#pragma once

#include <cmath>

#include "Tickable.h"
#include "AsciiConsoleOutput.h"
#include "Drawable.h"
#include "Point.h"
#include "StraightLine.h"

//helpful structs
struct Movement
{
    double speed{};
    double direction{}; //radians / PI, so 0 is south, .5 is west, 1 is north, 1.5 is east
};

/*
 * A traveler is that which travels in a LaneOfTravel
 */
class Traveler :
    public Drawable, public Tickable
{
public:
    virtual ~Traveler() {};

    XYPoint* getLastPosition() { return &lastPosition; };
    XYPoint* getPosition() { return &myPosition;  };
    Movement* getMovement() { return &myMovement;  };
    StraightLine* getLastTravel() { return &lastTravel;  };
    
    //Actually update the position
    virtual void travel();

    //Overload == to check IDs
    friend bool operator==(const Traveler& lhs, const Traveler& rhs);

    void draw(AsciiConsoleOutput* output); //Put the Ascii char at our position
    virtual char getAsciiChar() = 0;
    int getId() const { return id; };
private:
    int id{};
    XYPoint lastPosition{};
    XYPoint myPosition{};
    Movement myMovement{};
    StraightLine lastTravel{lastPosition, myPosition};
};

