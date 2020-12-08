#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Seat {
public:
    int ID = 0;

    int GetID()
    {
        std::cout << ID << std::endl;
        return ID;
    }

    bool Read()
    {
        bool line = false;
        std::string field;
        getline(std::cin, field);
            if (field.empty())
                return false;
            line = true;
            std::istringstream tmp(field);
            while (!tmp.eof())
            {
                std::string str;
                tmp >> str;
                int minRows = 0;
                int maxRows = 127;
                for (int i = 0; i < 7; i++) {
                    if (str[i] == 'F') {
                        maxRows = std::floor((minRows + maxRows) / 2.0f);
                    } else if (str[i] == 'B') {
                        minRows = std::round((minRows + maxRows) / 2.0f);
                    }
                }
                //std::cout << minRows << std::endl;
                int minColumns = 0;
                int maxColumns = 7;
                for (int i = 7; i < 10; i++) {
                    if (str[i] == 'R') {
                        minColumns = std::round((minColumns + maxColumns) / 2.0f);
                    }
                    else if (str[i] == 'L') {
                        maxColumns = std::floor((minColumns + maxColumns) / 2.0f);
                    }
                }
                //std::cout << minColumns << std::endl;
                //std::cout << minRows * 8 + minColumns << std::endl;
                ID = minRows * 8 + minColumns;
            }
        
        return line;
    }

};

int main()
{
    std::vector<Seat> list;
    Seat currentPlane;
    int count = 0;
    while (currentPlane.Read()) {
        list.push_back(currentPlane);
        currentPlane = Seat();
    }
    int myId = 0;
    int listId[1000] = {0};
    for (auto plane : list)
    {
        int id = plane.GetID();
        listId[id] = id;
    }
    for (int i = 1; i < 999; ++i) {
        if (listId[i] == 0 && listId[i - 1] != 0 && listId[i + 1] != 0) {
            myId = listId[i-1]+1;
            std::cout << "x : " << listId[i - 1] << "y : " << myId << "z : " << listId[i +1] << std::endl;
        }
    }
    std::cout << "myId : " << myId << std::endl;
}