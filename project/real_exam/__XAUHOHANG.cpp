#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s1{}, s2{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> s1;
    input >> s2;
    input.close();

    int soKyTuCanXoa{0};

    while (true) {
        
    }

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    
    output.close();

    return 0;
}
