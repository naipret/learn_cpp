#include <cmath>
#include <iostream>

bool isPrime(long long n) {
    // số nguyên tố
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i{5}; i <= int(std::sqrt(n)); i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }
    return true;
}

void primeFactorization(int n) {
    // phân thích một số thành thừa số nguyên tố
    if (n >= 1) {
        if (n == 1) {
            std::cout << 1;
        } else {
            while (n % 2 == 0) {
                std::cout << 2 << ' ';
                n /= 2;
            }
            while (n % 3 == 0) {
                std::cout << 3 << ' ';
                n /= 3;
            }
            int i{5};
            //! =============== n != 1 ===============
            while (n != 1) {
                while (n % i == 0) {
                    std::cout << i << ' ';
                    n /= i;
                }
                while (n % (i + 2) == 0) {
                    std::cout << i + 2 << ' ';
                    n /= (i + 2);
                }
                i += 6;
            }
        }
    }
}

bool isPerfectSquare(int n) {
    // số chính phương
    // là số căn bậc 2 của nó là một số nguyên
    if (n < 0) {
        return false;
    }
    int temp{int(std::sqrt(n))};
    return (temp * temp) == n;
}

int calculateFibonacci(int n) {
    // tính số fibonacci thứ n
    int first{1}, second{1}, next{2};
    for (int i{3}; i <= n; ++i) {
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}

int euclidAlgorithm(int a, int b) {
    // gcd của (a, b)
    if (a == 0) return b;
    return euclidAlgorithm(b % a, a);
}

int extendedEuclidAlgorithm(int a, int b, int &x, int &y) {
    // tìm các hệ số (x, y) khác để (ax, by) có đáp án khi gcd giống với (a, b)
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1{}, y1{};
    int gcd{extendedEuclidAlgorithm(b % a, a, x1, y1)};
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int devisorCount(int n) {
    // đếm các ước của một số
    int count{0};
    for (int i{1}; i <= int(std::sqrt(n)); ++i) {
        if (n % i == 0) {
            count++;
            // std::cout << i << " ";
            if (n % i != i) {
                count++;
                // std::cout << n / i << " ";
            }
        }
    }
    return count;
}

int main() {
    int n{7482930};
    int m{434325};

    if (isPrime(n)) {
        std::cout << n << " la so nguyen to!\n";
    } else {
        std::cout << n << " khong phai la so nguyen to!\n";
    }

    std::cout << '\n';

    primeFactorization(n);

    std::cout << '\n';
    std::cout << '\n';

    std::cout << "gcd(" << n << ',' << m << ") = " << euclidAlgorithm(n, m) << '\n';

    std::cout << '\n';

    int x{}, y{};
    std::cout << "gcd(" << n << ',' << m << ") = " << extendedEuclidAlgorithm(n, m, x, y) << '\n';
    std::cout << "He so khac: " << x << ' ' << y << '\n';

    std::cout << '\n';

    return 0;
}
