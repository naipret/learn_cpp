#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N{}, X{};

    ifstream input{};
    input.open("INPUT.INP");
    input >> N >> X;
    input.close();

    int tongTien{0};

    while (N - 8 >= 8) {
        N = (N - 8) - 4;
        tongTien += (8 * X);
    }
    while (N - 5 >= 5) {
        N = (N - 5) - 2;
        tongTien += (5 * X);
    }
    while (N - 3 >= 3) {
        N = (N - 3) - 1;
        tongTien += (3 * X);
    }
    while (N - 1 != 0) {
        N = N - 1;
        tongTien += (1 * X);
    }

    ofstream output{};
    output.open("OUTPUT.OUT");
    output << tongTien;
    output.close();

    return 0;
}
