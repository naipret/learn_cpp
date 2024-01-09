#include <algorithm>
#include <iostream>
#include <random>

int main() {
    const int size = 9;
    int numbers[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // reverse: Đảo ngược mảng
    std::reverse(numbers, numbers + size);

    std::cout << "Reversed array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // reverse_copy: Sao chép mảng đảo ngược vào mảng khác
    int reversedCopy[size];
    std::reverse_copy(numbers, numbers + size, reversedCopy);

    std::cout << "Reversed copy array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << reversedCopy[i] << " ";
    }
    std::cout << std::endl;

    // rotate: Xoay trái các phần tử trong mảng
    std::rotate(numbers, numbers + 3, numbers + size);

    std::cout << "Rotated array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // rotate_copy: Sao chép mảng xoay trái vào mảng khác
    // =================
    // ||  3 *        ||
    // 9 8 7 6 5 4 3 2 1
    //   <==============
    // 6 5 4 3 2 1 9 8 7
    int rotatedCopy[size];
    std::rotate_copy(numbers, numbers + 3, numbers + size, rotatedCopy);

    std::cout << "Rotated copy array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << rotatedCopy[i] << " ";
    }
    std::cout << std::endl;

    // random_shuffle: Xáo trộn ngẫu nhiên các phần tử trong mảng
    std::random_shuffle(numbers, numbers + size);

    std::cout << "Randomly shuffled array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // shuffle: Xáo trộn ngẫu nhiên các phần tử trong mảng sử dụng generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(numbers, numbers + size, gen);

    std::cout << "Shuffled array using generator: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
