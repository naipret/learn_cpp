// #include <cctype>
#include <iostream>

int main() {
    char c{};
    std::cin >> c;

    // if (std::isdigit(c)) {
    //     std::cout << "YES";
    // } else {
    //     std::cout << "NO";
    // }

    if ('0' <= c && c <= '9') {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
