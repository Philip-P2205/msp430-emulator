#pragma once

#include <cstdint>
#include <bitset>
#include "msp.hpp"

class Register
{
    friend class MSP430F5529;
    friend class Instruction;

private:
    Register(uint8_t size = 8, bool isConstant = false)
    {
        this->size = size;
        this->constant = isConstant;
    }

public:
    uint8_t &byte() { return *((uint8_t *)&data); }
    uint16_t &word() { return data; }
    bool isConstant() const { return constant; }

private:
    uint16_t data;
    uint8_t size;
    bool constant;
    uint16_t operator=(const uint16_t &d)
    {
        data = d;
        return data;
    }

public:
    operator const uint16_t() const
    {
        if (size == 8)
            return static_cast<uint8_t>(data);
        else
            return data;
    }

    const bool operator[](uint8_t index) const { return data & index; }
};
