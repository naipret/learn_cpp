#include <algorithm>  // Để sử dụng std::sort()
#include <iostream>

int main() {
    int myArray[] = {5, 2, 8, 1, 7};

    // Sử dụng std::sort để sắp xếp mảng
    std::sort(myArray, std::end(myArray));

    // In mảng sau khi đã sắp xếp
    std::cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }

    // Sử dụng std::sort và tham số 3: std::greater<int>() để sắp xếp mảng giảm dần
    std::sort(myArray, std::end(myArray), std::greater<int>());
    // <=> std::sort(myArray, std::end(myArray), [](int a, int b) { return a >= b; });

    // In mảng sau khi đã sắp xếp
    std::cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}
