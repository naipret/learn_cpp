#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>

int main() {
    constexpr int size = 10000;
    int array[size];

    // Khởi tạo mảng với giá trị tăng dần từ 1 đến size
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }

    std::cout << std::fixed << std::setprecision(10);

    // Đo thời gian cho std::max
    auto startMax = std::chrono::high_resolution_clock::now();

    //! =====================================================
    int max_value = std::max(array[0], array[size - 1]);
    //! =====================================================

    auto endMax = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationMax = endMax - startMax;

    // Đo thời gian cho std::max_element
    auto startMaxElement = std::chrono::high_resolution_clock::now();

    //! =====================================================
    int* max_element_iter = std::max_element(array, array + size);
    //! =====================================================

    auto endMaxElement = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationMaxElement = endMaxElement - startMaxElement;

    // In ra kết quả và thời gian chạy
    std::cout << "Max value: " << max_value << std::endl;
    std::cout << "std::max duration: " << durationMax.count() << " seconds" << std::endl;

    std::cout << "Max element: " << *max_element_iter << std::endl;
    std::cout << "std::max_element duration: " << durationMaxElement.count() << " seconds" << std::endl;

    return 0;
}
