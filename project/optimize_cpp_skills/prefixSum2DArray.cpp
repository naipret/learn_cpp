#include <ios>
#include <fstream>
#include <numeric>

int main() {
    std::ios::sync_with_stdio(false);
    constexpr std::streamsize bufferSize{1024};
    char inputBuffer[bufferSize];
    char outputBuffer[bufferSize];

    std::ifstream input{"input.inp", std::ios::binary};
    input.rdbuf()->pubsetbuf(inputBuffer, bufferSize);
    int row{}, col{};
    input >> row >> col;
    int arr[row + 1][col + 1] = {0};
    for (int r{1}; r <= row; ++r) {
        for (int c{1}; c <= col; ++c) {
            input >> arr[r][c];
        }
    }
    int pre2D[row + 1][col + 1] = {0};
    for (int r{1}; r <= row; ++r) {
        for (int c{1}; c <= col; ++c) {
            pre2D[r][c] = pre2D[r - 1][c] + pre2D[r][c - 1] - pre2D[r - 1][c - 1] + arr[r][c];
        }
    }

    std::ofstream output{"output.out", std::ios::binary};
    output.rdbuf()->pubsetbuf(outputBuffer, bufferSize);
    int q{};
    input >> q;
    while (q--) {
        int col1{}, col2{}, row1{}, row2{};
        input >> row1 >> row2 >> col1 >> col2;
        int ans{pre2D[row2][col2] - pre2D[row1 - 1][col2] - pre2D[row2][col1 - 1] + pre2D[row1 - 1][col1 - 1]};
        output << ans << ' ';
    }

    input.close();
    output.close();

    return 0;
}
