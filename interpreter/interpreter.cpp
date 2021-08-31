#include "interpreter.hpp"

constexpr unsigned int hash(const char *s, int off = 0)
{
    return !s[off] ? 5381 : (hash(s, off + 1) * 33) ^ s[off];
}

void Interpreter::loadFile(const char *path)
{
    this->src.clear();
    std::ifstream file(path);
    std::string line;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            line.erase(0, line.find_first_not_of(" \n\r\t"));
            line.erase(line.find_last_not_of(" \n\r\t") + 1);
            if (line[0] == ';' || line[0] == '.' || line.empty() || line.rfind("$C$DW$", 0) == 0)
                continue;

            this->src << line << "\n";
        }
    }
    file.close();
}

void Interpreter::interpret()
{
    std::string line;
    std::cout << "Commands: " << std::endl;
    while (std::getline(src, line))
    {
        if (line.back() == '|')
            interpret(line);
    }
}

void Interpreter::interpret(std::string &statement)
{
    auto pos = statement.find_first_of(' ');
    const char *cmd = statement.substr(0, pos).c_str();

    switch (hash(cmd))
    {
    case hash("MOV.W"):
        break;

    case hash("MOV.B"):
        break;

    case hash("XOR.B"):
        break;

    case hash("OR.B"):
        break;
    default:
        //std::cout << "Command not found!" << std::endl;
        break;
    }
}