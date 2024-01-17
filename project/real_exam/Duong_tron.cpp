#include <cmath>
#include <fstream>
#include <iostream>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double r{};
    int x1{}, y1{}, x2{}, y2{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> r >> x1 >> x2;
    input >> x2 >> y2;
    input.close();

    double ans = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

    std::ofstream output{};
    output.open("OUTPUT.OUT");
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