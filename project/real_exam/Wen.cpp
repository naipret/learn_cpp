#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n, m, y;

    ifstream input;
    input.open("Wen.inp");
    input >> x;
    input >> n;
    input >> m;
    input >> y;
    input.close();

    int soCuonCanTraTien = y - int(y / (n + 1));
    int ans = soCuonCanTraTien * m;

    ofstream output;
    output.open("Wen.out");
    if (ans > x) {
        output << "Thieu";
    } else {
        output << "Du";
    }
    output.close();

    return 0;
}