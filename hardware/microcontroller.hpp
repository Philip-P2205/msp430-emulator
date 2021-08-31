#pragma once

#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
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
    friend std::ostream &operator<<(std::ostream &stream, const Microcontroller &uC);
    std::vector<Port> ports;
};

class MSP430F5529
{
public:
    std::string json() const;

private:
    std::unique_ptr<Port> PA_L = std::make_unique<Port>(Port("Port1"));
    std::unique_ptr<Port> PA_H = std::make_unique<Port>(Port("Port2"));
    std::unique_ptr<Port> PB_L = std::make_unique<Port>(Port("Port3"));
    std::unique_ptr<Port> PB_H = std::make_unique<Port>(Port("Port4"));
    std::unique_ptr<Port> PC_L = std::make_unique<Port>(Port("Port5"));
    std::unique_ptr<Port> PC_H = std::make_unique<Port>(Port("Port6"));
    std::unique_ptr<Port> PD_L = std::make_unique<Port>(Port("Port7"));
    std::unique_ptr<Port> PD_H = std::make_unique<Port>(Port("Port8"));
};