#include <iostream>

int main() {
    int n{};
    std::cin >> n;

    unsigned long long s{0};
    for (unsigned long long i = 1ULL; i <= static_cast<unsigned long long>(n); ++i) {
        s += i;
    }

    std::cout << s;

    return 0;
}
