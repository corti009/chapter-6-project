#include <iostream>
#include <string>
#include <limits> 
#include <ios> 

void getRegInfo(std::string& name, int& accidents);
bool isLower(int val1, int val2);
void showLowest(std::string name, int accidents);
int main() {
    std::string region1Name, region2Name, region3Name;
    int region1Accidents = 0, region2Accidents = 0, region3Accidents = 0;
    std::string lowestName;
    int lowestAccidents = 0;
    std::cout << "--- Safest Driving Area Program ---\n";
    std::cout << "\nEnter information for Region 1:\n";
    getRegInfo(region1Name, region1Accidents);
    std::cout << "\nEnter information for Region 2:\n";
    getRegInfo(region2Name, region2Accidents);
    std::cout << "\nEnter information for Region 3:\n";
    getRegInfo(region3Name, region3Accidents);
    lowestName = region1Name;
    lowestAccidents = region1Accidents;
    if (isLower(region2Accidents, lowestAccidents)) {
        lowestName = region2Name;
        lowestAccidents = region2Accidents;
    }
    if (isLower(region3Accidents, lowestAccidents)) {
        lowestName = region3Name;
        lowestAccidents = region3Accidents;
    }
    std::cout << "\n--- Results ---\n";
    showLowest(lowestName, lowestAccidents);

    return 0;
}

void getRegInfo(std::string& name, int& accidents) {
    std::cout << "Enter region name: ";
    std::getline(std::cin >> std::ws, name);
    do {
        std::cout << "Enter number of accidents (>= 0): ";
        std::cin >> accidents;
        if (std::cin.fail() || accidents < 0) { 
            std::cout << "Invalid input. Number of accidents must be a non-negative integer.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (accidents < 0 || std::cin.fail()); 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool isLower(int val1, int val2) {
    return val1 < val2;
}
void showLowest(std::string name, int accidents) {
    std::cout << "The safest driving region is: " << name << "\n";
    std::cout << "with " << accidents << " accidents.\n";
}