#include <fstream>
#include <iostream>
#include <string>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str{};

    std::ifstream input{};
    input.open("MaDD.inp");
    input >> str;
    input.close();

    int tong{0};
    for (int i{0}; i < str.length(); ++i) {
        if (i <= 3) {
            tong += (str[i] - '0') * ((i * 2) + 3);
        } else if (i == 4) {
            tong += (str[i] - '0') * 2;
        } else if (i == 5) {
            tong += (str[i] - '0') * 4;
        } else {
            tong += (str[i] - '0') * 2;
        }
    }

    int soDu {tong % 9};
    char ans{};
    if (soDu == 8) {
        ans = 'K';
    } else {
        ans = int('A') + soDu;
    }

    std::ofstream output{};
    output.open("MaDD.out");
    output << ans;
    output.close();

    return 0;
}