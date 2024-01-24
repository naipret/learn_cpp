#include <cmath>
#include <iostream>

long long binaryExponent(long long a, long long b, long long mod = 1) {
    if (a <= 0 || b < 0) return -1;
    if (a == 0) return 0;
    // if (mod == 1) return 0;

    if (b == 0) return 1 % mod;
    if (b == 1) return a % mod;
    long long ans{binaryExponent(a, b / 2, mod)};
    if (b % 2 == 0) {
        return ((ans % mod) * (ans % mod)) % mod;
    } else {
        return ((((ans % mod) * (ans % mod)) % mod) * (a % mod)) % mod;
    }
}

int main() {
    // cho 2 so a va b, tinh a^b % (mod)
    long long a{}, b{};
    long long mod{};
    std::cin >> a >> b >> mod;

    long long ans{binaryExponent(a, b)};

    std::cout << ans << '\n';
    return 0;
}
