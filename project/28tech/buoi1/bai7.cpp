#include <iomanip>
#include <iostream>

int main() {
    int temperatureC{};
    std::cin >> temperatureC;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << (double(temperatureC) * (9.0 / 5.0)) + 32;
    
    return 0;
}
