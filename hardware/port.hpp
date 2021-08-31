#pragma once

#include <iostream>
#include <bitset>
#include <sstream>

class Port
{
public:
    Port(std::string name = "")
    {
        this->name_ = name;
    }
    std::string json() const;

private:
    friend std::ostream &operator<<(std::ostream &stream, const Port &port);

    // Getter/Setter
public:
    uint8_t in() const;
    void setIn(const uint8_t &in);

    uint8_t out() const;
    void setOut(const uint8_t &out);

    uint8_t dir() const;
    void setDir(const uint8_t &dir);

    uint8_t ren() const;
    void setRen(const uint8_t &ren);

    uint8_t ds() const;
    void setDs(const uint8_t &ds);

    uint8_t sel() const;
    void setSel(const uint8_t &sel);

    uint8_t ies() const;
    void setIes(const uint8_t &ies);

    uint8_t ie() const;
    void setIe(const uint8_t &ie);

    uint8_t ifg() const;
    void setIfg(const uint8_t &ifg);

private:
    uint8_t in_;  // Input
    uint8_t out_; // Output
    uint8_t dir_; // Direction
    uint8_t ren_; // Resistor Enable
    uint8_t ds_;  // Drive Strength
    uint8_t sel_; // Selection
    uint8_t ies_; // Interrupt Edge Select
    uint8_t ie_;  // Interrupt Enable
    uint8_t ifg_; // Interrupt Flag

    std::string name_;
};