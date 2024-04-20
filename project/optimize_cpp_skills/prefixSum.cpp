#include <ios>
#include <fstream>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    constexpr std::streamsize bufferSize{1024};
    char inputBuffer[bufferSize];
    char outputBuffer[bufferSize];

    std::ifstream input{"input.inp", std::ios::binary};
    input.rdbuf()->pubsetbuf(inputBuffer, bufferSize);
    int col{};
    input >> col;
    int arr[col + 1] = {0};
    for (int c{1}; c <= col; ++c) {
        input >> arr[c];
    }
    int pre[col + 1] = {0};
    std::partial_sum(arr + 1, arr + col + 1, pre + 1);

    std::ofstream output{"output.out", std::ios::binary};
    output.rdbuf()->pubsetbuf(outputBuffer, bufferSize);
    int q{};
    input >> q;
    while (q--) {
        int l{}, r{};
        input >> l >> r;
        int ans{pre[r] - pre[l - 1]};
        output << ans << ' ';
    }

    input.close();
    output.close();

    return 0;
}
