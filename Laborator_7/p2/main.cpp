#include <iostream>
#include "literals.h"

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    return 0;
}
