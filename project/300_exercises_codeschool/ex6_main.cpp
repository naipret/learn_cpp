#include <iostream>

void bubbleSort(int inputArr[]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (inputArr[i] > inputArr[j]) {
                std::swap(inputArr[i], inputArr[j]);
            }
        }
    }
}

int main() {
    int inputArr[3]{};
    std::cin >> inputArr[0] >> inputArr[1] >> inputArr[2];
    bubbleSort(inputArr);
    std::cout << "Tang dan: ";
    for (int i = 0; i < 3; ++i)
        std::cout << inputArr[i] << " ";
    std::cout << std::endl;
    return 0;
}
