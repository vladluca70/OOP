#pragma once
#include "BMW.h"
#include "Car.h"
#include "Weather.h"

class Circuit {
    private:
        Car * m_cars[10];
        int m_nrOfCars;
        char m_finalRanks[500];
        char m_whoDidNotFinish[500];
        float m_length;
        Weather m_weather;
    public:
        Circuit () : m_nrOfCars{ 0 }, m_length{ 0 }, m_weather( Weather::Sunny ), m_finalRanks{ "" }, m_whoDidNotFinish{ "" } { };
        int getLength() const { return m_length; };
        Weather getWeather() const { return m_weather; };
        void SetLength(float length) { m_length = length; };
        void SetWeather(Weather weather) { m_weather = weather; };
        void AddCar(Car* car);
        void Race();
        void ShowFinalRanks();
        void ShowWhoDidNotFinish();
        float getCar(int index) { return m_cars[index]->getFuelCapacity(); };
};
