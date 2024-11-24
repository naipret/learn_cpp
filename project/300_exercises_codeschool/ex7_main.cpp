#include <iostream>

int main() {
    int a{}, b{};
    std::cout << "Nhap a, b: ";
    std::cin >> a >> b;
    const double x{(double(-b)) * 1.0 / double(a)};
    std::cout << "x = " << x << std::endl;
    return 0;
}
