// #include "math.hpp"

#include <cmath>

namespace cst {
    template <typename T>
    T gcd(T a, T b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    template <typename T>
    T lcm(T a, T b) {
        return (a * b) / gcd(a, b);
    }

    template <typename T>
    T factorial(T n) {
        if (n < 0)
            return 0;
        T ans{1};
        for (T i{1}; i <= n; ++i)
            ans *= i;
        return ans;
    }
    template <typename T>
    T P(T n) {
        return factorial(n);
    }
    template <typename T>
    T giaiThua(T n) {
        return factorial(n);
    }

    template <typename T>
    T sumCSC(T n, T d = 1, T u1 = 1) {
        if (d == 0)
            return n * u1;
        return (n * u1) + (((n * (n - 1)) * d) / 2);
    }

    template <typename T>
    T sumCSN(T n, T q = 1, T u1 = 1) {
        if (q == 1)
            return u1 * n;
        return (u1 * (1 - pow(q, n))) / (1 - q);
    }

    template <typename T>
    T vectorLength(T xM, T yM, T xN = 0, T yN = 0) {
        return std::sqrt(std::pow(xN - xM, 2) + std::pow(yN - yM, 2));
    }

}  // namespace cst
