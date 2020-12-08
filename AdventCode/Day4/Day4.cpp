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
                std::string y = str.substr(4, str.size() - 4);
                std::cout << y << std::endl;
                if (!byr && n == "byr")
                {
                    std::istringstream tmp2(y);
                    int validator = 0;
                    tmp2 >> validator;
                    byr = (validator >= 1920 && validator <= 2002);
                    std::cout << validator << std::endl;
                }
                if (!iyr && n == "iyr")
                {
                    std::istringstream tmp2(y);
                    int validator = 0;
                    tmp2 >> validator;
                    iyr = (validator >= 2010 && validator <= 2020);
                    std::cout << validator << std::endl;
                }
                if (!eyr && n == "eyr")
                {
                    std::istringstream tmp2(y);
                    int validator = 0;
                    tmp2 >> validator;
                    eyr = (validator >= 2020 && validator <= 2030);
                    std::cout << validator << std::endl;
                }
                if (!hgt && n == "hgt")
                {
                    std::istringstream tmp2(y);
                    int validator = 0;
                    tmp2 >> validator;
                    std::string meter;
                    tmp2 >> meter;
                    if (meter == "cm")
                    {
                        hgt = (validator >= 150 && validator <= 193);
                    }
                    else if (meter == "in")
                    {
                        hgt = (validator >= 59 && validator <= 76);
                    }
                    std::cout << validator << std::endl;
                }
                if (!hcl && n == "hcl")
                {
                    std::string hastag = y.substr(0, 1);
                    std::string validator = y.substr(1, y.size() - 1);
                    if (hastag == "#" && validator.size() == 6)
                    {
                        hcl = true;
                        for (int i = 0; i < validator.size(); ++i) {
                            if (!((validator[i] >= '0' && validator[i] <= '9') || (validator[i] >= 'a' && validator[i] <= 'f')))
                            {
                                hcl = false;
                            }
                        }
                        std::cout << validator << std::endl;
                    }
                }
                if (!ecl && n == "ecl")
                {
                    if (y == "amb")
                    {
                        ecl = true;
                    }
                    else if (y == "blu")
                    {
                        ecl = true;
                    }
                    else if (y == "brn")
                    {
                        ecl = true;
                    }
                    else if (y == "gry")
                    {
                        ecl = true;
                    }
                    else if (y == "grn")
                    {
                        ecl = true;
                    }
                    else if (y == "hzl")
                    {
                        ecl = true;
                    }
                    else if (y == "oth")
                    {
                        ecl = true;
                    }
                }
                    std::cout << y << std::endl;
                    if (!pid && n == "pid")
                    {
                        if (y.size() == 9)
                        {
                            pid = true;
                        }
                    }
                

            }
        }
            std::cout << "End of Passport" << std::endl;
            return line;
        }
    
};

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