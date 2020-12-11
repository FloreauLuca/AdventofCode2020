
#include <iomanip>
#include <iostream>
#include <vector>

int main()
{
    int preambleSize = 25;
    std::vector<double> inputs;
    double input = 0.0;
    while (input != -1) {
        std::cin >> input;
        if (input != -1)
        {
            inputs.push_back(input);
        }
    }
    std::vector<bool> used = std::vector<bool>(inputs.size(), false);
    double lastInput = 0;
    int oneCount = 0;
    int threeCount = 0;
    while (std::find(used.begin(), used.end(), false) != used.end()) {
        bool found = false;
        int minCurrentIndex = -1;
        for (int i = 0; i < inputs.size(); i++) {
            if (used[i] == true) {
               continue; 
            }
            if (inputs[i] - lastInput <= 3 && inputs[i] - lastInput >= 0) {
                found = true;
                if (minCurrentIndex == -1) minCurrentIndex = i;
                if (inputs[i] < inputs[minCurrentIndex]) {
                    minCurrentIndex = i;
                }
            }
        }
        if (found) {
            if (lastInput + 1 == inputs[minCurrentIndex]) oneCount++;
            if (lastInput + 3 == inputs[minCurrentIndex]) threeCount++;
            lastInput = inputs[minCurrentIndex];
            used[minCurrentIndex] = true;
        }
    }
    lastInput += 3;
    threeCount++;
    std::cout << "lastInput : " << std::fixed << std::setprecision(20) << lastInput << std::endl;
    std::cout << "oneCount : " << std::fixed << std::setprecision(20) << oneCount << std::endl;
    std::cout << "threeCount : " << std::fixed << std::setprecision(20) << threeCount << std::endl;
    std::cout << "total : " << std::fixed << std::setprecision(20) << oneCount * threeCount << std::endl;
}
