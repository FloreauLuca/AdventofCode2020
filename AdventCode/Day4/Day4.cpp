#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Passport {
public:
    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool pid = false;

    bool IsCorrect()
    {
        return byr &&
            iyr &&
            eyr &&
            hgt &&
            hcl &&
            ecl &&
            pid;
    }

    bool Read()
    {
        bool line = false;
        std::string field;
        while (getline(std::cin, field)) {
            if (field.empty())
                break;
            line = true;
            std::istringstream tmp(field);
            while (!tmp.eof())
            {
                std::string str;
                tmp >> str;
                std::string n = str.substr(0, 3);
                if (!byr)
                    byr = (n == "byr");
                if (!iyr)
                    iyr = (n == "iyr");
                if (!eyr)
                    eyr = (n == "eyr");
                if (!hgt)
                    hgt = (n == "hgt");
                if (!hcl)
                    hcl = (n == "hcl");
                if (!ecl)
                    ecl = (n == "ecl");
                if (!pid)
                    pid = (n == "pid");

                std::cout << n << std::endl;
            }

            std::cout << field << std::endl;
        }
        std::cout << "End of Passport" << std::endl;
        return line;
    }
};
std::ostream& operator<<(std::ostream& os, const Passport& obj)
{
    //os << "MinNb : " << obj.minNb << " MaxNb : " << obj.maxNb << " char : " << obj.character << std::endl <<
    //    "Passport : " << obj.password << std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Passport& obj)
{
    
    //std::string field;
    //std::getline(std::cin, field)
    //while () {
    //    std::istringstream iss(line);
    //    char c;
    //    // For each character token...    
    //    while (iss >> c) {
    //        // Do something with c                                      }
    //    }
    //}
    //is >> obj.minNb;
    //is >> tmp;
    //is >> obj.maxNb;
    //is >> obj.character;
    //is >> tmp;
    //is >> obj.password;
    return is;
}

int main()
{
    std::vector<Passport> list;
    Passport currentPassport;
    int count = 0;
    while (currentPassport.Read()) {
        list.push_back(currentPassport);
        currentPassport = Passport();
    }
    for (auto passport : list)
    {
        if (passport.IsCorrect())
            count++;
    }
    std::cout << "NbValid : " << count << std::endl;
}