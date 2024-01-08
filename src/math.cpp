#include "math.hpp"

#include <cmath>  // to use std::sqrt(), std::pow()

namespace cst {
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (long long i{5}; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    bool isPrime(long long n) {
        if (n <= 1LL)
            return false;
        if (n == 2LL || n == 3LL)
            return true;
        if (n % 2LL == 0LL || n % 3LL == 0LL)
            return false;
        for (long long i{5LL}; i * i <= n; i += 6LL)
            if (n % i == 0LL || n % (i + 2LL) == 0LL)
                return false;
        return true;
    }
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    long long gcd(long long a, long long b) {
        if (a == 0LL)
            return b;
        return gcd(b % a, a);
    }
    int lcm(int a, int b) {
        return (a * b) / (gcd(a, b));
    }
    long long lcm(long long a, long long b) {
        return (a * b) / (gcd(a, b));
    }
    int factorial(int n) {
        if (n < 0)
            return -1;
        int factorial{1};
        for (int i{1}; i <= n; ++i)
            factorial *= i;
        return factorial;
    }
    long long factorial(long long n) {
        if (n < 0LL)
            return -1LL;
        long long factorial{1LL};
        for (long long i{1LL}; i <= n; ++i)
            factorial *= i;
        return factorial;
    }
    int sumCSC(int n, int d = 1, int u1 = 1) {
        return (n * u1) + (((n * (n - 1)) * d) / 2);
    }
    long long sumCSC(long long n, int d = 1, long long u1 = 1LL) {
        return (n * u1) + (((n * (n - 1LL)) * d) / 2LL);
    }
    double sumCSC(int n, double d = 1.0, double u1 = 1.0) {
        return (n * u1) + (((n * (n - 1.0)) * d) / 2.0);
    }
    long double sumCSC(long long n, double d = 1.0, long double u1 = 1.0L) {
        return (n * u1) + (((n * (n - 1.0L)) * d) / 2.0L);
    }
    int sumCSN(int n, int q = 1, int u1 = 1) {
        if (q == 1)
            return u1 * n;
        return (u1 * (1 - int(pow(q, n)))) / (1 - q);
    }
    long long sumCSN(long long n, int q = 1, long long u1 = 1LL) {
        if (q == 1LL)
            return u1 * n;
        return (u1 * (1LL - (long long)(pow(q, n)))) / (1LL - q);
    }
    double sumCSN(int n, double q = 1.0, double u1 = 1.0) {
        if (q == 1.0)
            return u1 * n;
        return (u1 * (1.0 - pow(q, n))) / (1.0 - q);
    }
    long double sumCSN(long long n, double q = 1.0, long double u1 = 1.0L) {
        if (q == 1.0L)
            return u1 * n;
        return (u1 * (1.0L - (long double)(pow(q, n)))) / (1.0L - q);
    }
    double vectorLength(double xM, double yM, double xN = 0.0, double yN = 0.0) {
        return std::sqrt(std::pow(xN - xM, 2.0) + std::pow(yN - yM, 2.0));
    }
    long double vectorLength(long double xM, long double yM, long double xN = 0.0L, long double yN = 0.0L) {
        return std::sqrt(std::pow(xN - xM, 2.0L) + std::pow(yN - yM, 2.0L));
    }
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}  // namespace cst
