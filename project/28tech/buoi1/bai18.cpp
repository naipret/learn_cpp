#include <cctype>
#include <iostream>

int main() {
    char c{};
    std::cin >> c;

    // if (std::islower(c)) {
    //     std::cout << "YES";
    // } else {
    //     std::cout << "NO";
    // }

    if ('a' <= c && c <= 'z') {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
