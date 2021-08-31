#include "port.hpp"

std::ostream &operator<<(std::ostream &stream, const Port &port)
{
    stream << port.name_;
    stream << "{";
    stream << "\"IN\":0b" << std::bitset<8>(port.in_);
    stream << ", \"OUT\":0b" << std::bitset<8>(port.out_);
    stream << ", \"DIR\":0b" << std::bitset<8>(port.dir_);
    stream << ", \"REN\":0b" << std::bitset<8>(port.ren_);
    stream << ", \"DS\":0b" << std::bitset<8>(port.ds_);
    stream << ", \"SEL\":0b" << std::bitset<8>(port.sel_);
    stream << ", \"IES\":0b" << std::bitset<8>(port.ies_);
    stream << ", \"IE\":0b" << std::bitset<8>(port.ie_);
    stream << ", \"IFG\":0b" << std::bitset<8>(port.ifg_);
    stream << "}";
    return stream;
}

std::string Port::json() const
{
    std::stringstream ss;

    ss << "{";
    ss << "\"IN\":" << static_cast<int>(this->in_);
    ss << ",\"OUT\":" << static_cast<int>(this->out_);
    ss << ",\"DIR\":" << static_cast<int>(this->dir_);
    ss << ",\"REN\":" << static_cast<int>(this->ren_);
    ss << ",\"DS\":" << static_cast<int>(this->ds_);
    ss << ",\"SEL\":" << static_cast<int>(this->sel_);
    ss << ",\"IES\":" << static_cast<int>(this->ies_);
    ss << ",\"IE\":" << static_cast<int>(this->ie_);
    ss << ",\"IFG\":" << static_cast<int>(this->ifg_);
    ss << ",\"name\":" << this->name_;
    ss << "}";
    return ss.str();
}

uint8_t Port::in() const
{
    return this->in_;
}

void Port::setIn(const uint8_t &in)
{
    this->in_ = in;
}

uint8_t Port::out() const
{
    return this->out_;
}

void Port::setOut(const uint8_t &out)
{
    this->out_ = out;
}

uint8_t Port::dir() const
{
    return this->dir_;
}

void Port::setDir(const uint8_t &dir)
{
    this->dir_ = dir;
}

uint8_t Port::ren() const
{
    return this->ren_;
}

void Port::setRen(const uint8_t &ren)
{
    this->ren_ = ren;
}

uint8_t Port::ds() const
{
    return this->ds_;
}

void Port::setDs(const uint8_t &ds)
{
    this->ds_ = ds;
}

uint8_t Port::sel() const
{
    return this->sel_;
}

void Port::setSel(const uint8_t &sel)
{
    this->sel_ = sel;
}

uint8_t Port::ies() const
{
    return this->ies_;
}

void Port::setIes(const uint8_t &ies)
{
    this->ies_ = ies;
}

uint8_t Port::ie() const
{
    return this->ie_;
}

void Port::setIe(const uint8_t &ie)
{
    this->ie_ = ie;
}

uint8_t Port::ifg() const
{
    return this->ifg_;
}

void Port::setIfg(const uint8_t &ifg)
{
    this->ifg_ = ifg;
}