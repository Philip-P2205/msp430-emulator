#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <bitset>
#include "main.hpp"
#include "hardware/msp.hpp"

int main(int argc, char const *argv[])
{
    MSP430F5529 msp;

    // std::stringstream ss(SOURCE);

    // std::ifstream file("resources/main.asm");

    // if (file.is_open())
    //     msp.interpret(file);
    // else
    //     std::cerr << "Could not open file" << std::endl;

    msp.R0.byte() = 15;
    msp.WDTCTL.word() = 128 + 256;

    std::cout << msp.PC << std::endl;
    std::cout << (int)msp.WDTCTL.byte() << std::endl;

    return 0;
}
