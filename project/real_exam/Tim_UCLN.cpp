#include <fstream>
#include <iostream>
#include <numeric>  // std::gcd

using namespace std;

//! để phân biệt giữa hàm gcd của std:: và hàm gcd tự viết đặt trong cst::
// namespace cst {
//     long long gcd(long long m, long long n) {
//         if (m == 0)
//             return n;
//         if (n == 0)
//             return m;
//         if (m == n)
//             return m;
//         if (m > n)
//             return gcd(m - n, n);
//         return gcd(m, n - m);
//     }
// }
//! ======================================================================

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long m, n;

    ifstream input;
    input.open("UCLN.inp");
    input >> m >> n;
    input.close();

    long long ans = std::gcd(m, n);

    ofstream output;
    output.open("UCLN.out");
    output << ans;
    output.close();

    return 0;
}