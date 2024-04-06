#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h"

class BMW : public Car {
    public:
        BMW() : Car { "BWM", 250, 4.5, 120, 100, 70 } {
        }
    virtual float timeToRace(float length, Weather weather) const;
};
