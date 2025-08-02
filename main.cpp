#include <iostream> 
#include <iomanip>
#include <string>   


const int MIN_FAHRENHEIT = 0;
const int MAX_FAHRENHEIT = 20;
double getCelsius(double fahrenheit);
int main() {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "--- Fahrenheit to Celsius Conversion Table ---\n\n";
    std::cout << std::setw(12) << "Fahrenheit" << std::setw(12) << "Celsius\n";
    std::cout << "------------------------\n"; 
    for (int f = MIN_FAHRENHEIT; f <= MAX_FAHRENHEIT; ++f) {
        double celsius = getCelsius(static_cast<double>(f));
        std::cout << std::setw(12) << static_cast<double>(f) << std::setw(12) << celsius << "\n";
    }
    return 0;
}
double getCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * (5.0 / 9.0);
}