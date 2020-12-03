#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

class Password {
public:
    int minNb = 0;
    int maxNb = 0;
    char character;
    std::string password = "";
    bool IsCorrect()
    {
        //size_t n = std::count(password.begin(), password.end(), character);
        //return (n >= minNb && n <= maxNb);
        if (minNb < 0) return false;
        int count = 0;
        if (password[minNb - 1] == character) count++;
        if (password[maxNb - 1] == character) count++;
        return count == 1;
    }
};
std::ostream& operator<<(std::ostream& os, const Password& obj)
{
    os << "MinNb : " << obj.minNb << " MaxNb : " << obj.maxNb << " char : " << obj.character << std::endl <<
        "Password : " << obj.password << std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Password& obj)
{
    char tmp;
    is >> obj.minNb;
    is >> tmp;
    is >> obj.maxNb;
    is >> obj.character;
    is >> tmp;
    is >> obj.password;
    return is;
}

int main()
{
    std::vector<std::string> list;
    std::string currentSlope = "";
    while (currentSlope != "-1") {
        std::cin >> currentSlope;
        if (currentSlope != "-1")
        {
            list.push_back(currentSlope);
        }
    }
    double multiplier = 1;
    std::vector<int> rightAddition = { 1, 3, 5, 7, 1 };
    std::vector<int> downAddition = { 1, 1, 1, 1, 2 };
    for (int time = 0; time < rightAddition.size(); ++time) {
        int count = 0;
        int currentRight = 0;
        for (int i = 0; i < list.size(); i+= downAddition[time]) {
            if (currentRight >= list[i].size()) {
                currentRight -= list[i].size();
            }
            std::string tmp = list[i];
            if (list[i][currentRight] == '#') {
                count++;
                tmp[currentRight] = 'X';
            } else {
                tmp[currentRight] = 'O';
            }
            std::cout << tmp << std::endl;
            currentRight += rightAddition[time];
        }
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "NbTree for " << rightAddition[time] << ";" << downAddition[time] << " : " << count << std::endl;
        multiplier *= count;
    }
    std::cout << "MultiplySum : " << std::fixed << std::setprecision(20) << multiplier << std::endl;
}
