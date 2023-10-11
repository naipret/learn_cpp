#include <iostream>

int main() {
    int a{}, b{};
    std::cout << "Nhap a, b: ";
    std::cin >> a >> b;
    double const x{(-b) * 1.0 / a};
    std::cout << "x = " << x << std::endl;
    return 0;
}
