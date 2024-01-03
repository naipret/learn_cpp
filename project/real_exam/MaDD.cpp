#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    ifstream input;
    input.open("MaDD.inp");
    input >> str;
    input.close();

    string_view str_v = str;
    int tong = 0;
    for (int i = 0; i < str_v.length(); ++i) {
        if (i <= 3) {
            tong += (str_v[i] - '0') * ((i * 2) + 3);
        } else if (i == 4) {
            tong += (str_v[i] - '0') * 2;
        } else if (i == 5) {
            tong += (str_v[i] - '0') * 4;
        } else {
            tong += (str_v[i] - '0') * 2;
        }
    }

    int soDu = tong % 9;
    char ans;
    if (soDu == 8) {
        ans = 'K';
    } else {
        ans = int('A') + soDu;
    }

    ofstream output;
    output.open("MaDD.out");
    output << ans;
    output.close();

    return 0;
}