#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double r;
    int x1, y1, x2, y2;

    ifstream input;
    input.open("Duong_tron.inp");
    input >> r >> x1 >> x2;
    input >> x2 >> y2;
    input.close();

    double ans = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    ofstream output;
    output.open("Duong_tron.out");
    if (r > ans) {
        output << "INSIDE";
    } else if (r < ans) {
        output << "OUTSIDE";
    } else {
        output << "ON";
    }
    output.close();

    return 0;
}