
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int preambleSize = 25;
    std::vector<double> preambles;
    std::vector<double> inputs;
    double input;
    for (int i = 0; i < preambleSize; ++i) {
        std::cin >> input;
        preambles.push_back(input);
    }
    while (input != -1) {
        std::cin >> input;
        if (input != -1)
        {
            inputs.push_back(input);
        }
    }
    double wrongInput = 0;
    for (auto input : inputs) {
        bool find = false;
        for (int i = preambles.size()-preambleSize; i < preambles.size(); i++) {
            for (int j = i; j < preambles.size(); j++) {
                if (preambles[i] + preambles[j] == input) {
                    find = true;
                    break;
                }
            }
            if (find)
                break;
        }
        if (!find)
        {
            wrongInput = input;
            break;
        }
        preambles.push_back(input);
    }
    double contigeousMax = 0;
    double contigeousMin = preambles.back() * preambles.back();
    std::cout << "wrongInput : " << std::fixed << std::setprecision(20) << wrongInput << std::endl;
    bool find = false;
    for (int i = 0; i < preambles.size(); i++) {
        for (int j = i; j < preambles.size(); j++) {
            contigeousMax = 0;
            contigeousMin = preambles.back() * preambles.back();
            double contigeousCount = 0;
            for (int k = i; k < j; k++) {
                if (contigeousMin > preambles[k]) {
                    contigeousMin = preambles[k];
                }
                if (contigeousMax < preambles[k]) {
                    contigeousMax = preambles[k];
                }
                contigeousCount += preambles[k];
                if (contigeousCount == wrongInput)
                    find = true;
                if (find)
                    break;
            }
            if (find)
                break;
        }
        if (find)
            break;
    }
    std::cout << "contigeousMin : " << std::fixed << std::setprecision(20) << contigeousMin << std::endl;
    std::cout << "contigeousMax : " << std::fixed << std::setprecision(20) << contigeousMax << std::endl;
    std::cout << "contigeous : " << std::fixed << std::setprecision(20) << contigeousMin+ contigeousMax << std::endl;
}
