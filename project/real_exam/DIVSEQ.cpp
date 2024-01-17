#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T_case{0};

    ifstream input{};
    input.open("INPUT.INP");
    input >> T_case;
    int d[T_case] = {};
    int N[T_case] = {};
    int arr[T_case][(5 * 1000) + 1];
    for (int i_case{0}; i_case < T_case; ++i_case) {
        input >> d[i_case] >> N[i_case];
        for (int j_arr{0}; j_arr < N[i_case]; ++j_arr) {
            input >> arr[i_case][j_arr];
        }
    }
    input.close();

    int subCount[T_case] = {0};

    for (int i_case{0}; i_case < T_case; ++i_case) {
        for (int subLong{1}; subLong <= N[i_case]; ++subLong) {
            int *itr{&(arr[i_case][0])};
            int *itrEnd{&(arr[i_case][0]) + N[i_case]};
            while (itr != itrEnd) {
                int sumOfSubRange{std::accumulate(itr, itr + subLong, 0)};
                if (sumOfSubRange % d[i_case] == 0) {
                    subCount[i_case]++;
                }
                itr++;
                if (*(itr + (subLong - 1)) == 0) {
                    break;
                }
            }
        }
        // std::cout << '\n';
    }

    ofstream output{};
    output.open("OUTPUT.OUT");
    for (int i_case{0}; i_case < T_case; ++i_case) {
        output << subCount[i_case] << '\n';
    }
    output.close();

    return 0;
}
