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
        if (password[minNb-1] == character) count++;
        if (password[maxNb-1] == character) count++;
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
    std::vector<Password> list;
    Password currentPassword;
    while (currentPassword.minNb != -1) {
        std::cin >> currentPassword;
        list.push_back(currentPassword);
    }
    int count = 0;
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].IsCorrect())
        {
            count++;
            std::cout << "Correct : ";
        } else {
            std::cout << "Not Correct : ";
        }
        std::cout << list[i] << std::endl;
    }
    std::cout << "NbValid : " << count << std::endl;
}