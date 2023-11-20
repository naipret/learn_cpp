#include <iostream>

int main() {
    double a1{}, b1{}, c1{};
    double a2{}, b2{}, c2{};
    std::cout << "Nhap a1, b1, c1: ";
    std::cin >> a1 >> b1 >> c1;
    std::cout << "Nhap a2, b2, c2: ";
    std::cin >> a2 >> b2 >> c2;
    const double d{a1 * b2 - a2 * b1}, dx{c1 * b2 - c2 * b1}, dy{a1 * c2 - a2 * c1};
    double x{}, y{};
    if (d != 0 && dx != 0 && dy != 0) {
        x = dx / d;
        y = dy / d;
    }
    std::cout << "x = " << x << "\n";
    std::cout << "y = " << y;
    return 0;
}
