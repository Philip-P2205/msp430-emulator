#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include <map>
#include "register.hpp"

class MSP430F5529
{
public:
    void interpret(std::istream &src);
    void interpretStatement(std::string statement);
    void run(const char *cmd, std::string args[2]);
    Register *getRegister(const char *reg);

    operator const char *() const;

    /* ******************************** Registers ********************************/
    /* Note: write access is restricted in the Register class */
public:
    Register R0, &PC = R0;            /* Program Counter */
    Register R1, &SP = R1;            /* Stack Pointer */
    Register R2, &SR = R2, &CG1 = R2; /* Status Register */
    Register R3, &CG2 = R3;           /* Constant Generator */
    Register R4;                      /* General Purpose Register */
    Register R5;                      /* General Purpose Register */
    Register R6;                      /* General Purpose Register */
    Register R7;                      /* General Purpose Register */
    Register R8;                      /* General Purpose Register */
    Register R9;                      /* General Purpose Register */
    Register R10;                     /* General Purpose Register */
    Register R11;                     /* General Purpose Register */
    Register R12;                     /* General Purpose Register */
    Register R13;                     /* General Purpose Register */
    Register R14;                     /* General Purpose Register */
    Register R15;                     /* General Purpose Register */

    // TODO: Expand System registers
    Register WDTCTL{16}; /* Watchdog Timer Control */

    // Port 1
    Register PAIN_L;  /* Port 1 Input */
    Register PAOUT_L; /* Port 1 Output */
    Register PADIR_L; /* Port 1 Direction */
    Register PAREN_L; /* Port 1 Resistor Enable */
    Register PADS_L;  /* Port 1 Drive Strenght */
    Register PASEL_L; /* Port 1 Selection */
    Register PAIES_L; /* Port 1 Interrupt Edge Select */
    Register PAIE_L;  /* Port 1 Interrupt Enable */
    Register PAIFG_L; /* Port 1 Interrupt Flag */

    // Port 2
    Register PAIN_H;  /* Port 2 Input */
    Register PAOUT_H; /* Port 2 Output */
    Register PADIR_H; /* Port 2 Direction */
    Register PAREN_H; /* Port 2 Resistor Enable */
    Register PADS_H;  /* Port 2 Drive Strenght */
    Register PASEL_H; /* Port 2 Selection */
    Register PAIES_H; /* Port 2 Interrupt Edge Select */
    Register PAIE_H;  /* Port 2 Interrupt Enable */
    Register PAIFG_H; /* Port 2 Interrupt Flag */

    // Port 3
    Register PBIN_L;  /* Port 3 Input */
    Register PBOUT_L; /* Port 3 Output */
    Register PBDIR_L; /* Port 3 Direction */
    Register PBREN_L; /* Port 3 Resistor Enable */
    Register PBDS_L;  /* Port 3 Drive Strenght */
    Register PBSEL_L; /* Port 3 Selection */

    // Port 4
    Register PBIN_H;  /* Port 4 Input */
    Register PBOUT_H; /* Port 4 Output */
    Register PBDIR_H; /* Port 4 Direction */
    Register PBREN_H; /* Port 4 Resistor Enable */
    Register PBDS_H;  /* Port 4 Drive Strenght */
    Register PBSEL_H; /* Port 4 Selection */

    // Port 5
    Register PCIN_L;  /* Port 5 Input */
    Register PCOUT_L; /* Port 5 Output */
    Register PCDIR_L; /* Port 5 Direction */
    Register PCREN_L; /* Port 5 Resistor Enable */
    Register PCDS_L;  /* Port 5 Drive Strenght */
    Register PCSEL_L; /* Port 5 Selection */

    // Port 6
    Register PCIN_H;  /* Port 6 Input */
    Register PCOUT_H; /* Port 6 Output */
    Register PCDIR_H; /* Port 6 Direction */
    Register PCREN_H; /* Port 6 Resistor Enable */
    Register PCDS_H;  /* Port 6 Drive Strenght */
    Register PCSEL_H; /* Port 6 Selection */

    // Port 7
    Register PDIN_L;  /* Port 7 Input */
    Register PDOUT_L; /* Port 7 Output */
    Register PDDIR_L; /* Port 7 Direction */
    Register PDREN_L; /* Port 7 Resistor Enable */
    Register PDDS_L;  /* Port 7 Drive Strenght */
    Register PDSEL_L; /* Port 7 Selection */

    //Port 8
    Register PDIN_H;  /* Port 8 Input */
    Register PDOUT_H; /* Port 8 Output */
    Register PDDIR_H; /* Port 8 Direction */
    Register PDREN_H; /* Port 8 Resistor Enable */
    Register PDDS_H;  /* Port 8 Drive Strenght */
    Register PDSEL_H; /* Port 8 Selection */
};