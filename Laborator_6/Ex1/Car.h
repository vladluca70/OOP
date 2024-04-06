#pragma once
#include <cstring>
#include "Weather.h"

class Car
{
private:
    char name[50];
    float fuelCapacity;
    float fuelConsumption;
    int speedWhenRain;
    int speedWhenSunny;
    int speedwhenSnow;
public:
    Car()
    {
        strcpy(name, "Car");
        fuelCapacity=0;
        fuelConsumption=0;
        speedWhenRain=0;
        speedWhenSunny=0;
        speedwhenSnow=0;
    }

    Car(const char * carName, float carFuelCapacity, float carFuelConsumption, int carSpeedwhenRain,
                int carSpeedwhenSunny, int carSpeedwhenSnow)
    {
        strcpy(name,carName);
        fuelCapacity=carFuelCapacity;
        fuelConsumption=carFuelConsumption;
        speedWhenRain=carSpeedwhenRain;
        speedWhenSunny=carSpeedwhenSunny;
        speedwhenSnow=carSpeedwhenSnow;
    }
    virtual float timeToRace(float length, Weather weather) const
    {
        return -1;
    }

    const char * getName() const
    {
        return name;
    }

    int getFuelCapacity() const
    {
        return fuelCapacity;
    }

    int getFuelConsumption() const
    {
        return fuelConsumption;
    }

    int getSpeedWhenRain() const
    {
        return speedWhenRain;
    }

    int getSpeedWhenSunny() const
    {
        return speedWhenSunny;
    }

    int getSpeedWhenSnow() const
    {
        return speedwhenSnow;
    }
};
