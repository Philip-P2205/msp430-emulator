#pragma once
#include <cstdint>
#include "register.hpp"

enum class Instructions : uint8_t
{
    /*
    * Status Bit Effect of operation at end of line:
    * 
    * * = Status bit is affected.
    * – = Status bit is not affected.
    * 0 = Status bit is cleared.
    * 1 = Status bit is set.
    */
    // !MSP430 Double-Operand (Format I) Instructions  V N Z C
    MOV,      // src,dst | src → dst                       – – – –
    ADD,      // src,dst | src + dst → dst                 * * * *
    ADDC,     // src,dst | src + dst + C → dst             * * * *
    SUB,      // src,dst | dst + .not.src + 1 → dst        * * * *
    SUBC,     // src,dst | dst + .not.src + C → dst        * * * *
    CMP,      // src,dst | dst - src                       * * * *
    DADD,     // src,dst | src + dst + C → dst (decimally) * * * *
    BIT,      // src,dst | src .and. dst                   0 * * Z
    BIC,      // src,dst | .not.src .and. dst → dst        – – – –
    BIS,      // src,dst | src .or. dst → dst              – – – –
    OR = BIS, // This is not part of the documentation, however it is used in the output of the CCS assembly.
    XOR,      // src,dst | src .xor. dst → dst             * * * Z
    AND,      // src,dst | src .and. dst → dst             0 * * Z

    // !MSP430 Single-Operand (Format II) Instructions   V N Z C
    RRC,  // dst | C → MSB →.......LSB → C               0 * * *
    RRA,  // dst | MSB → MSB →....LSB → C                0 * * *
    PUSH, // src | SP - 2 → SP, src → SP                 – – – –
    SWPB, // dst | bit 15...bit 8 ↔ bit7...bit0          – – – –
    CALL, // dst | Call subroutine in lower 64KB         – – – –
    RETI, //       TOS → SR, SP + 2 → SP                 * * * *
          //       TOS → PC, SP + 2 → SP
    SXT,  // dst | Register mode: bit 7 → bit8...bit19   0 * * Z
          //       Other modes: bit 7 → bit8...bit15

    // !MSP430 Jump Instructions
    JEQ,       // Label | Jump to label if zero bit is set
    JZ = JEQ,  //
    JNE,       // Label | Jump to label if zero bit is reset
    JNZ = JNE, //
    JC,        // Label | Jump to label if carry bit is set
    JNC,       // Label | Jump to label if carry bit is reset
    JN,        // Label | Jump to label if negative bit is set
    JGE,       // Label | Jump to label if (N .XOR. V) = 0
    JL,        // Label | Jump to label if (N .XOR. V) = 1
    JMP,       // Label | Jump to label unconditionally

    // !Extended Double-Operand (Format I) Instructions V N Z C
    MOVX,  // src,dst | src → dst                       – – – –
    ADDX,  // src,dst | src + dst → dst                 * * * *
    ADDCX, // src,dst | src + dst + C → dst             * * * *
    SUBX,  // src,dst | dst + .not.src + 1 → dst        * * * *
    SUBCX, // src,dst | dst + .not.src + C → dst        * * * *
    CMPX,  // src,dst | dst – src                       * * * *
    DADDX, // src,dst | src + dst + C → dst (decimal)   * * * *
    BITX,  // src,dst | src .and. dst                   0 * * Z
    BICX,  // src,dst | .not.src .and. dst → dst        – – – –
    BISX,  // src,dst | src .or. dst → dst              – – – –
    XORX,  // src,dst | src .xor. dst → dst             * * * Z
    ANDX,  // src,dst | src .and. dst → dst             0 * * Z

    // !Extended Single-Operand (Format II) Instructions                                        n           V N Z C
    CALLA,  // dst     | Call indirect to subroutine (20-bit address)                                       – – – –
    POPM,   // #n,Rdst | Pop n 16/20-bit registers from stack                                      1 to 16     – – – –
    PUSHM,  // #n,Rsrc | Push n 16/20-bit registers to stack                                       1 to 16     – – – –
    PUSHXA, // src     | Push 8-, 16-, or 20-bit source to stack                                            – – – –
    RRCM,   // #n,Rdst | Rotate right Rdst n bits through carry (16-, 20-bit register)          1 to 4      0 * * *
    RRUM,   // #n,Rdst | Rotate right Rdst n bits unsigned (16-, 20-bit register)               1 to 4      0 * * *
    RRAM,   // #n,Rdst | Rotate right Rdst n bits arithmetically (16-, 20-bit register)         1 to 4      0 * * *
    RLAM,   // #n,Rdst | Rotate left Rdst n bits arithmetically (16-, 20-bit register)          1 to 4      * * * *
    RRCXA,  // dst     | Rotate right dst through carry (8-, 16-, 20-bit data)                  1           0 * * *
    RRUXA,  // Rdst    | Rotate right dst unsigned (8-, 16-, 20-bit)                            1           0 * * *
    RRAXA,  // dst     | Rotate right dst arithmetically                                        1           0 * * *
    SWPBX,  // dst     | Exchange low byte with high byte                                       1           – – – –
    SXTX,   // dst     | Bit7 → bit8 ... MSB 1                                                              0 * * Z
    // SXTX,   // Rdst    | Bit7 → bit8 ... bit19 1                                                            0 * * Z
};

enum class OperationType : uint8_t
{
    B = 8,
    W = 16,
    A = 20,
};

class Instruction
{
private:
    Instruction(Instructions instruction, OperationType type, Register *src, Register *dst)
    {
        this->instruction = instruction;
        this->type = type;
        this->src = src;
        this->dst = dst;
    }

    Instruction &operator()()
    {
        exec();
        return *this;
    }
    void exec();

private:
    Instructions instruction;
    OperationType type;
    Register *src;
    Register *dst;
};