#include <fstream>
#include <iostream>

// using namespace std;

namespace cst {
    long long gcd(long long a, long long b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long m{}, n{};

    std::ifstream input{};
    input.open("UCLN.inp");
    input >> m >> n;
    input.close();

    long long ans = cst::gcd(m, n);

    std::ofstream output{};
    output.open("UCLN.out");
    output << ans;
    output.close();

    return 0;
}