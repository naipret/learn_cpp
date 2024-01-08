#ifndef CST_MATHS_HPP
#define CST_MATHS_HPP

#include <cmath>  // To use std::sqrt(), std::pow()

namespace cst {
    template <typename T>
    T gcd(T a, T b);
    template <typename T>
    T lcm(T a, T b);
    template <typename T>
    T factorial(T n);
    template <typename T>
    T sumCSC(T n, T d = 1, T u1 = 1);
    template <typename T>
    T sumCSN(T n, T q = 1, T u1 = 1);
    template <typename T>
    T vectorLength(T xM, T yM, T xN = 0, T yN = 0);
}  // namespace cst

#endif /* CST_MATHS_HPP */
