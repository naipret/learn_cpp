#include <fstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    constexpr streamsize bufferSize{8 * 1024};
    char buffer[bufferSize];

    ifstream input{};
    input.rdbuf()->pubsetbuf(buffer, bufferSize);
    input.open("input.inp", ios_base::binary);

    input.close();

    ofstream output{};
    output.rdbuf()->pubsetbuf(buffer, bufferSize);
    output.open("output.out", ios_base::binary);

    output.close();

    return 0;
}
