#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include "main.hpp"
#include "hardware/msp.hpp"

const std::string SOURCE = std::string(/*"main:\n"*/ "\n") +
                           "MOV.W     #23168,&WDTCTL+0      ; [] |9|\n" +
                           "MOV.B     #1,&PADIR_L+0         ; [] |10|\n" +
                           //    "$C$L1:\n" +
                           "OR.B     #1,&PAOUT_L+0         ; [] |13|\n";
//    "JMP       $C$L1                 ; [] |11|\n" +
//    "NOP       ; []";

void interpret(std::string statement);
void interpret();

int main(int argc, char const *argv[])
{
    MSP430F5529 msp;

    std::stringstream ss(SOURCE);

    msp.interpret(ss);

    std::cout << std::bitset<16>(msp.getRegister("WDTCTL")->data) << std::endl;
    std::cout << std::bitset<8>(msp.getRegister("PADIR_L")->data) << std::endl;
    std::cout << std::bitset<8>(msp.getRegister("PAOUT_L")->data) << std::endl;
    std::cout << __cplusplus << std::endl;
    return 0;
}
