#include <cctype>
#include <iostream>

int main() {
    char c{};
    std::cin >> c;

    if (std::isupper(c) || std::islower(c)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
