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

    while (N >= (8 + 4)) {
        tongTien += 8 * 10;
        N -= (8 + 4);
    }
    while (N >= (5 + 2)) {
        tongTien += 5 * 10;
        N -= (5 + 2);
    }
    while (N >= (3 + 1)) {
        tongTien += 3 * 10;
        N -= (3 + 1);
    }
    while (N != 0) {
        tongTien += 10;
        N -= 1;
    }

    ofstream output{};
    output.open("OUTPUT.OUT");
    output << tongTien;
    output.close();

    return 0;
}
