#include <algorithm>
#include <iostream> // Để sử dụng std::sort()

int main() {
    
    int myArray[] = {5, 2, 8, 1, 7};

    // Sử dụng std::sort để sắp xếp mảng
    std::sort(myArray, std::end(myArray));

    // In mảng sau khi đã sắp xếp
    std::cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}
