#include <chrono>
#include <iostream>
#include <random>

int main() {
    constexpr int iterations{1000000};  // Số lần lặp
    std::cout << "So lan thuc hien: " << iterations << "\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    auto start_time{std::chrono::high_resolution_clock::now()};

    for (int i{0}; i < iterations; ++i) {
        int randomNum{dis(gen)};
        // Sử dụng randomNum để tránh việc compiler loại bỏ mã không sử dụng
    }

    auto end_time{std::chrono::high_resolution_clock::now()};
    auto duration{std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time)};

    std::cout << "Time using <random>: " << duration.count() << " seconds." << std::endl;

    return 0;
}
