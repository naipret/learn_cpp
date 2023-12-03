#include <iomanip>
#include <iostream>

int main() {
    int a{}, b{};
    std::cin >> a >> b;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << a + b << " " << a - b << " " << a * b << " " << static_cast<double>(a) / static_cast<double>(b);

    return 0;
}
