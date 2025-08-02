#include <iostream>
#include <limits>
#include <ios>
#include <cctype>


void getLength_Width(double& length, double& width);
double calcPerimeter(double length, double width);
double calcArea(double length, double width);
void displayProperties(double perimeter, double area);

int main() {
    double length = 0.0, width = 0.0;
    double perimeter = 0.0, area = 0.0;
    char choice;

    do {
        getLength_Width(length, width);
        perimeter = calcPerimeter(length, width);
        area = calcArea(length, width);
        displayProperties(perimeter, area);

        std::cout << "\nDo you want to process another rectangle? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        choice = std::toupper(choice);
    } while (choice == 'Y');

    return 0;
}
void getLength_Width(double& length, double& width) {
    do {
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> length;

        if (std::cin.fail() || length <= 0) {
            std::cout << "Invalid input. Length must be a positive number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (length <= 0 || std::cin.fail()); 
    do {
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;

        if (std::cin.fail() || width <= 0) {
            std::cout << "Invalid input. Width must be a positive number.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    } while (width <= 0 || std::cin.fail()); 
}

double calcPerimeter(double length, double width) {
    return 2 * (length + width);
}

double calcArea(double length, double width) {
    return length * width;
}

void displayProperties(double perimeter, double area) {
    std::cout << "The perimeter is: " << perimeter << std::endl;
    std::cout << "The area is: " << area << std::endl;
}