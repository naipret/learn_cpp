#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T_case{};

    std::ifstream input{};
    input.open("INPUT.INP");
    std::ofstream output{};
    output.open("OUTPUT.OUT");

    input >> T_case;

    for (int testCase{0}; testCase < T_case; ++testCase) {
        int d{}, N{};
        input >> d >> N;
        int arr[N] = {};
        for (int i{0}; i < N; ++i) {
            input >> arr[i];
        }

        int count{0};
        for (int range{1}; range <= N; ++range) {
            int *itr{arr + range};
            while (itr != (arr + N + 1)) {
                int tempSum{std::accumulate(itr - range, itr, 0)};
                if (tempSum % d == 0) {
                    count++;
                }
                itr++;
            }
        }
        output << count << '\n';
    }

    input.close();
    output.close();

    return 0;
}
