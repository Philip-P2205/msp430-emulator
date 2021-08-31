#include "microcontroller.hpp"

std::ostream &operator<<(std::ostream &stream, const Microcontroller &uC)
{
    stream << "{\n";
    stream << "\"ports\":[";
    for (size_t i = 0; i < uC.ports.size(); i++)
        stream << "\n\tP" << i << ":" << uC.ports[i] << ",";
    stream << "\n]";
    stream << "\n}";
    return stream;
}

std::string Microcontroller::json() const
{
    std::stringstream ss;
    ss << "{";
    ss << "\"ports\":[";
    for (Port p : this->ports)
        ss << p.json() << ",";
    ss << "]";
    ss << "}";
    return ss.str();
}