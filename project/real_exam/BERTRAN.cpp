#include <cmath>
#include <fstream>
#include <iostream>

// using namespace std;

bool isPrime(int n) {
    if (n <= 3) {
        return true;
    }
    if ((n % 2) == 0 || (n % 3) == 0) {
        return false;
    }
    for (int i{5}; i <= int(std::sqrt(n)); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::ifstream input{};
    input.open("INPUT.INP");
    std::ofstream output{};
    output.open("OUTPUT.OUT");

    int n{};

    while (input >> n) {
        int pCount{0};
        if (n <= 9) {
            if ((n + 1) % 2 == 0) {
                for (int i{n + 2}; i < (2 * n); i += 2) {
                    if (isPrime(i)) {
                        pCount++;
                    }
                }
            } else {
                for (int i{n + 1}; i < (2 * n); i += 2) {
                    if (isPrime(i)) {
                        pCount++;
                    }
                }
            }
        } else {
            // tu 10 tro len
            int slash{5};  // phan tach du lieu, de ap dung duoc isPrime
            do {
                slash += 6;
            } while (slash <= n);

            if (slash == (n + 1)) {
                for (int i{slash}; i < (2 * n); i += 2) {
                    if (isPrime(i)) {
                        pCount++;
                    }
                }
            } else {
                for (int i{n + 1}; i < slash; ++i) {
                    if (isPrime(i)) {
                        pCount++;
                    }
                }
                for (int i{slash}; i < (2 * n); ++i) {
                    if (isPrime(i)) {
                        pCount++;
                    }
                }
            }
        }
        output << pCount << '\n';
    }

    input.close();
    output.close();

    return 0;
}
