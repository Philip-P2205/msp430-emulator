#include "msp.hpp"

constexpr size_t hash(const char *s, int off = 0)
{
    return !s[off] ? 5381 : (hash(s, off + 1) * 33) ^ s[off];
}
inline std::string trim(std::string str)
{
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
    return str;
}

MSP430F5529::operator const char *() const
{
    return "Test";
}

void MSP430F5529::interpret(std::istream &src)
{
    std::string line;
    while (std::getline(src, line))
    {
        line = trim(line);
        // TODO: error prevention, removal of unused code
        if (line.empty())
            continue;
        if (line.at(0) == '.')
            continue;
        if (line.at(0) == ';')
            continue;

        if (line.find("$C$DW$") == 0)
            continue;

        if (line.back() == ':')
            continue;

        interpretStatement(line);
    }
}

void MSP430F5529::interpretStatement(std::string statement)
{
    statement = trim(statement.substr(0, statement.find_first_of(';')));
    size_t pos = statement.find_first_of(' ');
    std::string cmd = statement.substr(0, pos);
    std::string arguments = trim(statement.substr(pos, statement.length()));
    std::string args[2];

    if ((pos = arguments.find_first_of(',')) != std::string::npos)
    { // constains 2 arguments
        args[0] = arguments.substr(0, pos);
        if (args[0].at(0) == '#')
            args[0].erase(0, 1);
        args[1] = arguments.substr(pos + 1, arguments.length());
        if (args[1].at(0) == '&')
            args[1].erase(0, 1);
        if (pos = args[1].find('+'))
            args[1].erase(pos, args[1].length());
    }
    else
    { // constains only one argument
        args[0] = arguments;
        // args[1] = std::string();
    }
    run(cmd.c_str(), args);
}

void MSP430F5529::run(const char *cmd, std::string args[2])
{
    Register *reg;
    switch (hash(cmd))
    {
    case hash("MOV.W"):
    case hash("MOV.B"):
        reg = getRegister(args[1].c_str());
        reg->data = stoi(args[0]);
        break;

    case hash("OR.B"):
        reg = getRegister(args[1].c_str());
        reg->data |= stoi(args[0]);
        break;

    case hash("NOP"):
        break;

    default:
        break;
    }
}

Register *MSP430F5529::getRegister(const char *reg)
{
    switch (hash(reg))
    {
    //System registers
    case hash("WDTCTL"):
        return &WDTCTL;

    // Port 1
    case hash("PAIN_L"):
        return &PAIN_L;
    case hash("PAOUT_L"):
        return &PAOUT_L;
    case hash("PADIR_L"):
        return &PADIR_L;
    case hash("PAREN_L"):
        return &PAREN_L;
    case hash("PADS_L"):
        return &PADS_L;
    case hash("PASEL_L"):
        return &PASEL_L;
    case hash("PAIES_L"):
        return &PAIES_L;
    case hash("PAIE_L"):
        return &PAIE_L;
    case hash("PAIFG_L"):
        return &PAIFG_L;

    // Port 2
    case hash("PAIN_H"):
        return &PAIN_H;
    case hash("PAOUT_H"):
        return &PAOUT_H;
    case hash("PADIR_H"):
        return &PADIR_H;
    case hash("PAREN_H"):
        return &PAREN_H;
    case hash("PADS_H"):
        return &PADS_H;
    case hash("PASEL_H"):
        return &PASEL_H;
    case hash("PAIES_H"):
        return &PAIES_H;
    case hash("PAIE_H"):
        return &PAIE_H;
    case hash("PAIFG_H"):
        return &PAIFG_H;

    // Port 3
    case hash("PBIN_L"):
        return &PBIN_L;
    case hash("PBOUT_L"):
        return &PBOUT_L;
    case hash("PBDIR_L"):
        return &PBDIR_L;
    case hash("PBREN_L"):
        return &PBREN_L;
    case hash("PBDS_L"):
        return &PBDS_L;
    case hash("PBSEL_L"):
        return &PBSEL_L;

    // Port 4
    case hash("PBIN_H"):
        return &PBIN_H;
    case hash("PBOUT_H"):
        return &PBOUT_H;
    case hash("PBDIR_H"):
        return &PBDIR_H;
    case hash("PBREN_H"):
        return &PBREN_H;
    case hash("PBDS_H"):
        return &PBDS_H;
    case hash("PBSEL_H"):
        return &PBSEL_H;

    // Port 5
    case hash("PCIN_L"):
        return &PCIN_L;
    case hash("PCOUT_L"):
        return &PCOUT_L;
    case hash("PCDIR_L"):
        return &PCDIR_L;
    case hash("PCREN_L"):
        return &PCREN_L;
    case hash("PCDS_L"):
        return &PCDS_L;
    case hash("PCSEL_L"):
        return &PCSEL_L;

    // Port 6
    case hash("PCIN_H"):
        return &PCIN_H;
    case hash("PCOUT_H"):
        return &PCOUT_H;
    case hash("PCDIR_H"):
        return &PCDIR_H;
    case hash("PCREN_H"):
        return &PCREN_H;
    case hash("PCDS_H"):
        return &PCDS_H;
    case hash("PCSEL_H"):
        return &PCSEL_H;

    // Port 7
    case hash("PDIN_L"):
        return &PDIN_L;
    case hash("PDOUT_L"):
        return &PDOUT_L;
    case hash("PDDIR_L"):
        return &PDDIR_L;
    case hash("PDREN_L"):
        return &PDREN_L;
    case hash("PDDS_L"):
        return &PDDS_L;
    case hash("PDSEL_L"):
        return &PDSEL_L;

    // Port 8
    case hash("PDIN_H"):
        return &PDIN_H;
    case hash("PDOUT_H"):
        return &PDOUT_H;
    case hash("PDDIR_H"):
        return &PDDIR_H;
    case hash("PDREN_H"):
        return &PDREN_H;
    case hash("PDDS_H"):
        return &PDDS_H;
    case hash("PDSEL_H"):
        return &PDSEL_H;

    default:
        return nullptr;
    }
}