#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Group {
public:
    int nbQuestion = 0;
    std::vector<char> answers;
    bool started = false;

    int GetNbQuestion()
    {
        for (auto answer : answers) {
            std::cout << answer;
        }
        std::cout << answers.size() << std::endl;
        return answers.size();
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
                if (!started)
                {
                    started = true;
                    for (int i = 0; i < str.size(); ++i) {
                        answers.push_back(str[i]);
                    }
                }
                else
                {
                    for (int i = 0; i < answers.size(); ++i) {
                        std::cout << "Test : " << str.find_first_of(answers[i]) << std::endl;
                        if (str.find_first_of(answers[i]) == std::string::npos) {
                            answers.erase(std::remove(answers.begin(), answers.end(), answers[i]));
                        }
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
    std::vector<Group> list;
    Group currentGroup;
    int count = 0;
    while (currentGroup.Read()) {
        list.push_back(currentGroup);
        currentGroup = Group();
    }
    int total = 0;
    for (auto group : list)
    {
        total += group.GetNbQuestion();
    }
    std::cout << "total : " << total << std::endl;
}