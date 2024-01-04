#ifndef CST_MATHS_HPP
#define CST_MATHS_HPP

#include <string>

namespace cst {
    std::string quadraticEquation(const double &a, const double &b = 1.0, const double &c = 1.0);
    int gcd(int a, int b);
    long long gcd(long long a, long long b);
    int lcm(int a, int b);
    long long lcm(long long a, long long b);
}  // namespace cst

#endif /* CST_MATHS_HPP */
