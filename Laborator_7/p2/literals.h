#pragma once

constexpr float operator"" _Kelvin(long double kelvin)
{
    return kelvin - 273.15;
}

constexpr float operator"" _Fahrenheit(long double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

