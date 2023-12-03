#include <iostream>

int main() {
    int a{}, b{};
    std::cin >> a >> b;

    if (a % b == 0) {
        std::cout << a;
    } else {
        std::cout << b * ((a / b) + 1);
    }

    return 0;
}
