#include <iomanip>
#include <iostream>

int main() {
    int n{};
    std::cin >> n;

    long double s{0};
    for (long double i = 1.0L; i <= static_cast<long double>(n); ++i) {
        s += (1.0L / (i * (i + 1.0L)));
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << s;

    return 0;
}
