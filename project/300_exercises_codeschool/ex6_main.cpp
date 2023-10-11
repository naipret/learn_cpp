#include <iostream>

void bubbleSort(int input_arr[]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (input_arr[i] > input_arr[j]) {
                std::swap(input_arr[i], input_arr[j]);
            }
        }
    }
}

int main() {
    int input_arr[3]{};
    std::cin >> input_arr[0] >> input_arr[1] >> input_arr[2];
    bubbleSort(input_arr);
    std::cout << "Tang dan: ";
    for (int i = 0; i < 3; ++i)
        std::cout << input_arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
