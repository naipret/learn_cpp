#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    constexpr int iterations = 1000000000;  // Số lần lặp

    std::srand(std::time(0));

    clock_t start_time = clock();  // Thời điểm bắt đầu

    for (int i = 0; i < iterations; ++i) {
        int randomNum = std::rand();
        // Sử dụng randomNum để tránh việc compiler loại bỏ mã không sử dụng
    }

    clock_t end_time = clock();  // Thời điểm kết thúc

    std::cout << "Time using rand(): " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds." << std::endl;

    return 0;
}
