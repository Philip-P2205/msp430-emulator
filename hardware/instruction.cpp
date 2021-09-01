#include "instruction.hpp"

void Instruction::exec()
{
    switch (instruction)
    {
    // !MSP430 Double-Operand (Format I) Instructions
    case Instructions::MOV:
        if (type == OperationType::B)
            dst->byte() = src->byte();
        else if (type == OperationType::W)
            dst->word() = src->word();
        break;
    case Instructions::ADD:
        if (type == OperationType::B)
            dst->byte() += src->byte();
        else if (type == OperationType::W)
            dst->word() += src->word();
        break;
    case Instructions::ADDC:
        break;
    case Instructions::SUB:
        if (type == OperationType::B)
            dst->byte() += ~(src->byte()) + 1;
        else if (type == OperationType::W)
            dst->word() += ~(src->word()) + 1;
        break;
    case Instructions::SUBC:
        break;
    case Instructions::CMP:
        break;
    case Instructions::DADD:
        break;
    case Instructions::BIT:
        break;
    case Instructions::BIC:
        if (type == OperationType::B)
            dst->byte() &= ~src->byte();
        else if (type == OperationType::W)
            dst->word() &= ~src->word();
        break;
    case Instructions::BIS:
        // case Instructions::OR:
        if (type == OperationType::B)
            dst->byte() |= src->byte();
        else if (type == OperationType::W)
            dst->word() |= src->word();
        break;
    case Instructions::XOR:
        if (type == OperationType::B)
            dst->byte() ^= src->byte();
        else if (type == OperationType::W)
            dst->word() ^= src->word();
        break;
    case Instructions::AND:
        if (type == OperationType::B)
            dst->byte() &= src->byte();
        else if (type == OperationType::W)
            dst->word() &= src->word();
        break;

    // !MSP430 Single-Operand (Format II) Instructions
    case Instructions::RRC:
        break;
    case Instructions::RRA:
        break;
    case Instructions::PUSH:
        break;
    case Instructions::SWPB:
        break;
    case Instructions::CALL:
        break;
    case Instructions::RETI:
        break;
    case Instructions::SXT:
        break;

    // !MSP430 Jump Instructions
    case Instructions::JEQ:
        // case Instructions::JZ:
        break;
    case Instructions::JNE:
        // case Instructions::JNZ:
        break;
    case Instructions::JC:
        break;
    case Instructions::JNC:
        break;
    case Instructions::JN:
        break;
    case Instructions::JGE:
        break;
    case Instructions::JL:
        break;
    case Instructions::JMP:
        break;

    // !Extended Double-Operand (Format I) Instructions
    case Instructions::MOVX:
        break;
    case Instructions::ADDX:
        break;
    case Instructions::ADDCX:
        break;
    case Instructions::SUBX:
        break;
    case Instructions::SUBCX:
        break;
    case Instructions::CMPX:
        break;
    case Instructions::DADDX:
        break;
    case Instructions::BITX:
        break;
    case Instructions::BICX:
        break;
    case Instructions::BISX:
        break;
    case Instructions::XORX:
        break;
    case Instructions::ANDX:
        break;

    // !Extended Single-Operand (Format II) Instructions
    case Instructions::CALLA:
        break;
    case Instructions::POPM:
        break;
    case Instructions::PUSHM:
        break;
    case Instructions::PUSHXA:
        break;
    case Instructions::RRCM:
        break;
    case Instructions::RRUM:
        break;
    case Instructions::RRAM:
        break;
    case Instructions::RLAM:
        break;
    case Instructions::RRCXA:
        break;
    case Instructions::RRUXA:
        break;
    case Instructions::RRAXA:
        break;
    case Instructions::SWPBX:
        break;
    case Instructions::SXTX:
        break;
    }
}