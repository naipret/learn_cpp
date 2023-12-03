#include <cmath>
#include <iostream>

int main() {
    long long n{};
    std::cin >> n;

    // long long sChan{0}, sLe{0};
    // for (long long i = 2LL; i <= n; i += 2LL) {
    //     sChan += i;
    // }
    // for (long long i = 1LL; i <= n; i += 2LL) {
    //     sLe += i;
    // }

    // std::cout << sChan - sLe;

    if (n % 2 == 0) {
        std::cout << n / 2LL;
    } else {
        std::cout << -((n + 1LL) / 2LL);
    }

    return 0;
}
