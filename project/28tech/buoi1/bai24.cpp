#include <cctype>
#include <iostream>

int main() {
    char c{};
    std::cin >> c;

    if (std::isalpha(c)) {
        std::cout << char((c == 'Z' || c == 'z') ? 'a' : (std::tolower(c) + 1));
    } else {
        std::cout << "INVALID";
    }

    return 0;
}
