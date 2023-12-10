#include <cmath>
#include <iostream>

int main() {
    double a{}, b{};
    std::cin >> a >> b;

    std::cout << std::floor(b) - std::floor(a);

    return 0;
}
