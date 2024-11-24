#ifndef CST_MATHS_HPP
#define CST_MATHS_HPP

namespace cst {
    // std::string quadraticEquation(double a, double b = 1.0, double c = 1.0);
    int gcd(int a, int b);
    long long gcd(long long a, long long b);
    int lcm(int a, int b);
    long long lcm(long long a, long long b);
    int factorial(int n);
    long long factorial(long long n);
    int sumCSC(int n, int d = 1, int u1 = 1);
    long long sumCSC(long long n, int d = 1, long long u1 = 1LL);
    int sumCSN(int n, int q = 1, int u1 = 1);
    long long sumCSN(long long n, int q = 1, long long u1 = 1LL);
}  // namespace cst

#endif /* CST_MATHS_HPP */
