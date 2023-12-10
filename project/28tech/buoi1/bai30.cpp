#include <iostream>

int main() {
    long long a{}, b{}, c{};
    std::cin >> a >> b >> c;

    if (a / b == c || a / c == b || b / a == c || b / c == a || c / a == b || c / b == a) {
        std::cout << '/';
    } else {
        std::cout << "NOSOL";
    }

    return 0;
}
