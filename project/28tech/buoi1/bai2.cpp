#include <iostream>

int main() {
    int x{};
    std::cin >> x;

    std::cout << (x * x * x) + (3 * (x * x)) + x + 1;

    return 0;
}
