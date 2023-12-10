#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double a{}, b{}, c{};
    std::cin >> a >> b >> c;

    double delta{(b * b) - (4.0 * a * c)};
    if (delta < 0) {
        std::cout << "NO";
        return 0;
    } else if (delta == 0) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << -b / (2.0 * a) << ' ' << -b / (2.0 * a);
        return 0;
    } else {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << (-b + sqrt(delta)) / (2.0 * a) << ' ' << (-b - sqrt(delta)) / (2.0 * a);
        return 0;
    }

    return 0;
}
