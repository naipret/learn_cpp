#include <cctype>
#include <iostream>

int main() {
    char c{};
    std::cin >> c;

    if (std::isupper(c)) {
        std::cout << std::tolower(c) << std::endl;
    } else {
        std::cout << c << std::endl;
    }

    return 0;
}
