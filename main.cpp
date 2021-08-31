#include "main.hpp"
#include <memory>

int main(int argc, char const *argv[])
{
    // Microcontroller uC = Microcontroller();

    // std::cout << uC << std::endl;
    MSP430F5529 msp = MSP430F5529();

    std::cout << msp.json() << std::endl;
    // Interpreter i = Interpreter(&((Microcontroller)msp));

    // i.loadFile("resources/main.asm");
    // i.printSrc();
    // i.interpret();

    return 0;
}