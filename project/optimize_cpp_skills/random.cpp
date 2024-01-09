#include <iostream>
#include <random>

int main() {
    constexpr int iterations = 1000000000;  // Số lần lặp

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    clock_t start_time = clock();  // Thời điểm bắt đầu

    for (int i = 0; i < iterations; ++i) {
        int randomNum = dis(gen);
        // Sử dụng randomNum để tránh việc compiler loại bỏ mã không sử dụng
    }

    clock_t end_time = clock();  // Thời điểm kết thúc

    std::cout << "Time using <random>: " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds." << std::endl;

    return 0;
}
