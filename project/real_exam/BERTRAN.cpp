#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

// using namespace std;

bool primes[(2 * 3000000) + 1];

void sieve(int n) {
    std::memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for (int i{2}; i <= (2 * 3000000); ++i) {
        if (primes[i]) {
            for (int j{i * 2}; j <= (2 * 3000000); j += i) {
                primes[j] = false;
            }
        }
    }
}

int solve(int n) {
    int count{0};
    for (int i{n + 1}; i < (2 * n); ++i) {
        if (primes[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::ifstream input{};
    input.open("INPUT.INP");
    std::ofstream output{};
    output.open("OUTPUT.OUT");

    int n{};
    sieve(n);
    while (input >> n) {
        output << solve(n) << '\n';
    }

    input.close();
    output.close();

    return 0;
}
