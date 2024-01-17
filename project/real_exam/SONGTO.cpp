#include <iostream>
#include <fstream>

// using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i{5}; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> n;
    input.close();

    int sumEach{0};
    int temp{n};
    while (temp > 0) {
        sumEach += temp % 10;
        temp /= 10;
    }

    bool ans{isPrime(n) && isPrime(sumEach)};

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    output << ans;
    output.close();

    return 0;
}
