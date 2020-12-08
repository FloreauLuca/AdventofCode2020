#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

class Bag {
public:
    std::map<std::string, float> containedColors;
    bool containGold = false;
    bool containedByGold = false;
    bool readed = false;
    std::string myColor;
    bool Read()
    {

        bool line = false;
        std::string field;
        getline(std::cin, field);
        if (field.empty())
            return false;
        line = true;
        std::istringstream tmp(field);
        std::string color;
        tmp >> color;
        myColor += color;
        tmp >> color;
        myColor += color;
        if (myColor == "shinygold") {
            containedByGold = true;
        }
        std::cout << myColor << std::endl;
        std::string str;
        tmp >> str;
        //std::cout << str << std::endl;
        tmp >> str;
        //std::cout << str << std::endl;
        while (!tmp.eof())
        {
            int nb;
            tmp >> nb;
            if (nb == 0) {
                break;
            }
            std::cout << nb << std::endl;
            std::string newColor = "";
            tmp >> color;
            newColor += color;
            tmp >> color;
            newColor += color;
            containedColors[newColor] = nb;
            //if (newColor == "shinygold") {
            //    containGold = true;
            //}
            std::cout << newColor << std::endl;
            tmp >> str;
            //std::cout << str << std::endl;
        }

        std::cout << "End of Bag" << std::endl;
        return line;
    }

};
std::ostream& operator<<(std::ostream& os, const Bag& obj)
{
    os << "Gold : " << obj.containGold << " Colors : ";
    for (auto bag : obj.containedColors) {
        os << bag.first << ", ";
    }
    return os;
}
int main()
{
    std::vector<Bag> list;
    std::map<std::string, float> newBag;
    Bag currentGroup;
    while (currentGroup.Read()) {
        list.push_back(currentGroup);
        if (currentGroup.containedByGold)
            for (auto containedByGold : currentGroup.containedColors) {
                newBag[containedByGold.first] = containedByGold.second;
            }
        currentGroup = Bag();
    }
    int count = 0;
    std::map<std::string, float> oldBag = newBag;
    newBag.clear();
    while (!oldBag.empty())
    {
        for (auto old : oldBag) {
            for (auto& bag : list)
            {
                if (bag.myColor == old.first) {
                    bag.containedByGold = true;
                    for (auto containedByGold : bag.containedColors) {
                        if (newBag.find(containedByGold.first) == newBag.end())
                            newBag[containedByGold.first] = 0;
                        newBag[containedByGold.first] += containedByGold.second * oldBag[bag.myColor];
                    }
                    std::cout << bag.myColor << std::endl;
                    break;
                }
            }
        }
        for (auto bag : oldBag) {
            count += bag.second;
        }
        oldBag = newBag;
        newBag.clear();
    }
    std::cout << "total : " << count << std::endl;
}

//int main()
//{
//    std::vector<Bag> list;
//    std::vector<Bag> newBag;
//    Bag currentGroup;
//    while (currentGroup.Read()) {
//        list.push_back(currentGroup);
//        if (currentGroup.containGold)
//            newBag.push_back(currentGroup);
//        currentGroup = Bag();
//    }
//    int count = 0;
//    std::vector<Bag> oldBag = newBag;
//    newBag.clear();
//    while (!oldBag.empty())
//    {
//        for (int i = 0; i < oldBag.size(); ++i) {
//            for (auto& bag : list)
//            {
//                if (bag.containGold) continue;
//                for (auto& containedColor : bag.containedColors) {
//                    if (containedColor == oldBag[i].myColor) {
//                        bag.containGold = true;
//                        newBag.push_back(bag);
//                        std::cout << bag.myColor << std::endl;
//                        break;
//                    }
//                }
//            }
//        }
//        count += oldBag.size();
//        oldBag = newBag;
//        newBag.clear();
//    }
//    std::cout << "total : " << count << std::endl;
//}
