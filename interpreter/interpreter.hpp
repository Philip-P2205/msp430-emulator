#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "../hardware/microcontroller.hpp"

class Interpreter
{
public:
    Interpreter(Microcontroller &uC) : Interpreter(&uC) {}
    Interpreter(Microcontroller *uC)
    {
        this->uC = uC;
    }

    void loadFile(const char *path);
    void printSrc() const { std::cout << src.str() << std::endl; }
    void interpret();

private:
    void interpret(std::string &statement);
    std::stringstream src;
    Microcontroller *uC;
};