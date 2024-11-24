#include <cmath>
#include <iostream>

int main() {
    double a{}, b{}, c{};
    std::cout << "Nhap a, b, c: ";
    std::cin >> a >> b >> c;
    const double delta{(b * b) - (4.0 * a * c)};
    if (delta == 0) {
        std::cout << "x = " << (-b) / (2.0 * a) << std::endl;
    } else if (delta > 0) {
        std::cout << "x1 = " << ((-b) + sqrt(delta)) / (2.0 * a) << std::endl;
        std::cout << "x2 = " << ((-b) - sqrt(delta)) / (2.0 * a) << std::endl;
    } else {
        std::cout << std::endl;
    }
    return 0;
}
