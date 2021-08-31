#pragma once

#include <sstream>
#include <iostream>
#include <vector>
#include "Port.hpp"

class Microcontroller
{
public:
    Microcontroller(const int ports = 8)
    {
        this->ports = std::vector<Port>(ports);
    }

    std::string json() const;


private:
    friend std::ostream& operator<<(std::ostream& stream, const Microcontroller& uC);
    std::vector<Port> ports;
};