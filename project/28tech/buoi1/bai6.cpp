#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    int x1{}, y1{}, x2{}, y2{};
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    return 0;
}
