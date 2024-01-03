#include <fstream>
#include <iostream>

int main() {
    int x{};

    std::ifstream input{};
    input.open("input.txt");
    //* do something
    input >> x;
    input.close();

    //* do something
    x += 1;

    std::ofstream output{};
    output.open("output.txt");
    //* do something
    output << x;
    output.close();

    return 0;
}