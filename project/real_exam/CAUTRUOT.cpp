#include <iostream>
#include <fstream>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tang{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> tang;
    input.close();

    int tongSoBuoc{0};
    if ((9 - tang) % 2 == 0) {
        tongSoBuoc = int((9 - tang) / 2);
    } else {
        tongSoBuoc = int(((9 - tang) / 2)) + 1;
    }

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    output << tongSoBuoc;
    output.close();

    return 0;
}
