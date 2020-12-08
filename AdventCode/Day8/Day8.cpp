#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Instruction {
public:
    enum class Type {
        NOP,
        ACC,
        JMP
    };
    int value = 0;
    Type type = Type::NOP;

    bool Read()
    {
        bool line = false;
        std::string field;
        getline(std::cin, field);
        if (field.empty())
            return false;
        line = true;
        std::istringstream tmp(field);
        std::string str;
        tmp >> str;
        if (str == "nop") {
            type = Type::NOP;
        }
        if (str == "jmp") {
            type = Type::JMP;
        }
        if (str == "acc") {
            type = Type::ACC;
        }
        tmp >> value;
        std::cout << value << std::endl;
        return line;
    }

};

int main()
{
    std::vector<Instruction> list;
    Instruction currentInstruction;
    int count = 0;
    while (currentInstruction.Read()) {
        list.push_back(currentInstruction);
        currentInstruction = Instruction();
    }
    int accumulator = 0;
    std::vector<int> modifiedLine;
    int line = 0;
    bool infiniteLoop = true;

    while (infiniteLoop)
    {
        accumulator = 0;
        std::vector<int> readLine;
        int line = 0;
        infiniteLoop = false;
        bool modified = false;

        while (line < list.size()) {
            if (std::find(readLine.begin(), readLine.end(), line) != readLine.end())
            {
                infiniteLoop = true;
                break;
            }
            readLine.push_back(line);
            switch (list[line].type) {
            case Instruction::Type::NOP:
                if (std::find(modifiedLine.begin(), modifiedLine.end(), line) == modifiedLine.end() && !modified)
                {
                    modifiedLine.push_back(line);
                    modified = true;
                    std::cout << line << std::endl;
                    line += list[line].value;
                }
                else
                {
                    line++;
                }
                break;
            case Instruction::Type::ACC:
                accumulator += list[line].value;
                line++;
                break;
            case Instruction::Type::JMP:
                if (std::find(modifiedLine.begin(), modifiedLine.end(), line) == modifiedLine.end() && !modified)
                {
                    modifiedLine.push_back(line);
                    modified = true;
                    std::cout << line << std::endl;
                    line++;
                }
                else
                {
                    line += list[line].value;
                }
                break;
            default:;
            }
        }
    }
    std::cout << "total : " << accumulator << std::endl;
}