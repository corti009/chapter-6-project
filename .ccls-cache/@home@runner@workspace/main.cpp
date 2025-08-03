#include <iostream>
#include <iomanip>
#include <cmath> 


const double SQFT_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_CHARGE_PER_HOUR = 25.00;

double getRooms();
double getPricePerGallon();
double getSqFt();
void displayEstimate(double gallons, double hours, double paintCost, double laborCost, double totalCost);

int main() {
    double totalGallons = 0.0;
    double totalHours = 0.0;
    double totalPaintCost = 0.0;
    double totalLaborCost = 0.0;
    double pricePerGallon = 0.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Paint Job Estimator\n";
    std::cout << "===================\n\n";

    int numRooms = getRooms();
    pricePerGallon = getPricePerGallon();
    for (int i = 1; i <= numRooms; ++i) {
        std::cout << "\nRoom " << i << ":\n";
        double sqFt = getSqFt();
        double gallonsForRoom = ceil(sqFt / SQFT_PER_GALLON); 
        double hoursForRoom = (sqFt / SQFT_PER_GALLON) * HOURS_PER_GALLON;
        totalGallons += gallonsForRoom;
        totalHours += hoursForRoom;
    }
    totalPaintCost = totalGallons * pricePerGallon;
    totalLaborCost = totalHours * LABOR_CHARGE_PER_HOUR;
    double totalJobCost = totalPaintCost + totalLaborCost;
    displayEstimate(totalGallons, totalHours, totalPaintCost, totalLaborCost, totalJobCost);

    return 0;
}
double getRooms() {
    int rooms;
    do {
        std::cout << "Enter the number of rooms to be painted: ";
        std::cin >> rooms;
        if (rooms < 1) { 
            std::cout << "Invalid input. Number of rooms must be 1 or more.\n";
        }
    } while (rooms < 1);
    return rooms;
}
double getPricePerGallon() {
    double price;
    do {
        std::cout << "Enter the price of paint per gallon: $";
        std::cin >> price;
        if (price < 10.00) {
            std::cout << "Invalid input. Price per gallon must be at least $10.00.\n";
        }
    } while (price < 10.00);
    return price;
}
double getSqFt() {
    double sqFt;
    do {
        std::cout << "  Enter the square footage of wall space: ";
        std::cin >> sqFt;
        if (sqFt < 0) {
            std::cout << "  Invalid input. Square footage cannot be negative.\n";
        }
    } while (sqFt < 0);
    return sqFt;
}
void displayEstimate(double gallons, double hours, double paintCost, double laborCost, double totalCost) {
    std::cout << "\n--- Final Estimate ---\n";
    std::cout << "Gallons of paint required: " << gallons << " gallons\n";
    std::cout << "Hours of labor required:   " << hours << " hours\n";
    std::cout << "Cost of the paint:         $" << paintCost << "\n";
    std::cout << "Labor charges:             $" << laborCost << "\n";
    std::cout << "Total cost of paint job:   $" << totalCost << "\n";
}