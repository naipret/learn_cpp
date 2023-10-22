#include <iostream>
#include <fstream>

int main() {

    std::ifstream input;
    input.open("input.txt");
    // do something
    std::string input_array[5] = {};
    std::cout << "There is 5 line in \"input.txt\" file\n";
    for (auto i = 0; i < 5; ++i) {
        getline(input, input_array[i]);
        std::cout << " |- Input line " << i + 1 << ": " << input_array[i] << "\n";
    }
    // do something
    input.close();

    std::cout << std::endl;

    std::ofstream ouput;
    ouput.open("output.txt");
    // do something
    std::cout << "";
    ouput.close();

    return 0;
}