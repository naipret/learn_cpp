#include <cctype>
#include <iostream>

int main() {
    char c{};
    std::cin >> c;

    if (std::islower(c)) {
        std::cout << std::toupper(c) << std::endl;
    } else {
        std::cout << c << std::endl;
    }

    return 0;
}
