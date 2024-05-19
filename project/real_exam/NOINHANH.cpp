#include <fstream>
#include <ios>
#include <numeric>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    constexpr std::streamsize buffer_size{4096};
    char buffer[buffer_size];

    int n{};

    std::ifstream input{};
    input.rdbuf()->pubsetbuf(buffer, buffer_size);
    input.open("INPUT.INP", std::ios::binary);
    input >> n;
    int arr[n] = {};
    for (int i{0}; i < n; ++i) {
        input >> arr[i];
    }
    input.close();

    // for (int i{1}; i < n; ++i) {
    //     arr[i] = arr[i - 1] + arr[i];
    // }


    int ans{std::accumulate(arr, arr + n, 0)};

    std::ofstream output{};
    output.rdbuf()->pubsetbuf(buffer, buffer_size);
    output.open("OUTPUT.OUT", std::ios::binary);
    // for (int &i : arr) {
    //     output << i << ' ';
    // }
    output << ans;
    output.close();

    return 0;
}
