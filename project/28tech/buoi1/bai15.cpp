#include <iostream>

int main() {
    long long n{};
    std::cin >> n;

    std::cout << (((n % 3 == 0) && (n % 5 == 0)) ? true : false);

    return 0;
}
