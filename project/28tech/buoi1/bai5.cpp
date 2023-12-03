#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    int r{};
    std::cin >> r;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << 2.0 * M_PI * (r * 1.0) << " " << M_PI * (r * r * 1.0);

    return 0;
}
