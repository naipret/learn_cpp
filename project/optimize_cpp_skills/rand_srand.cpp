#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    constexpr int iterations{1000000};  // Số lần lặp
    std::cout << "So lan thuc hien: " << iterations << "\n";

    std::srand(std::time(0));

    auto start_time{std::chrono::high_resolution_clock::now()};

    for (int i{0}; i < iterations; ++i) {
        int randomNum{std::rand()};
        // Sử dụng randomNum để tránh việc compiler loại bỏ mã không sử dụng
    }

    auto end_time{std::chrono::high_resolution_clock::now()};
    auto duration{std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time)};

    std::cout << "Time using rand(): " << duration.count() << " seconds." << std::endl;

    return 0;
}
