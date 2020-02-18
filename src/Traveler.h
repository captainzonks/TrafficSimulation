#pragma once
#include "Tickable.h"
#include "AsciiConsoleOutput.h"
#include "Drawable.h"

//helpful structs
struct Position
{
    double x{};
    double y{};
};

struct Movement
{
    double speed{};
    double direction{}; //radians / PI, so 0 is south, .5 is west, 1 is north, 1.5 is east
};

/*
 * A traveler is that which travels in a LaneOfTravel
 */
class Traveler :
    public Drawable
{
public:
    Position* getPosition() { return &myPosition;  };
    Movement* getMovement() { return &myMovement;  };
    
    //Actually update the position
    virtual void travel();

    //Overload == to check IDs
    friend bool operator==(const Traveler& lhs, const Traveler& rhs);

    void draw(AsciiConsoleOutput* output); //Put the Ascii char at our position
    virtual char getAsciiChar() = 0; //
private:
    int id{};
    Position myPosition{};
    Movement myMovement{};
};

