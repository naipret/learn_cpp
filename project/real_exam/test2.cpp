#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Hàm tính giai thừa
double factorial(double n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Hàm tính tổ hợp C(n, k)
double combination(double n, double k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Hàm tính số đường đi từ ô (1, 1) đến ô (n, n)
double countPaths2(double n) {
    return combination(2 * n, n);
}

const unsigned long long MOD = 1e9 + 7;

unsigned long long countPaths(unsigned long long n) {
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(n + 1, 0));

    // Khởi tạo giá trị cho trường hợp n = 1
    dp[1][1] = 1;

    for (unsigned long long i = 1; i <= n; ++i) {
        for (unsigned long long j = 1; j <= n; ++j) {
            // Cập nhật số đường đi từ ô (i, j) bằng tổng số đường đi từ ô bên trên và ô bên trái
            if (i < n) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j < n) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
        }
    }

    return dp[n][n];
}

int main() {
    unsigned long long n;
    std::cin >> n;

    std::cout << std::fixed;

    // Ghi kết quả vào tệp DUONGDI.OUT
    std::cout << countPaths(n) << endl
              << endl;
    std::cout << countPaths2(n - 1);

    return 0;
}
