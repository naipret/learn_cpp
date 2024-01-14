#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

int intReverse(int temp) {
    int reversed{0};
    while (temp > 0) {
        reversed = (reversed * 10) + (temp % 10);
        temp /= 10;
    }
    return reversed;
}

std::string strReverse(int temp) {
    std::string reversed{std::to_string(temp)};
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {
    int num_iterations{1000000};  // Số lần lặp để đo thời gian
    std::cout << "So lan thuc hien: " << num_iterations << "\n";

    // Đo thời gian thực thi hàm intReverse
    auto start_time_int{std::chrono::high_resolution_clock::now()};
    for (int i{0}; i < num_iterations; i++) {
        intReverse(i);
    }
    auto end_time_int{std::chrono::high_resolution_clock::now()};
    auto duration_int{std::chrono::duration_cast<std::chrono::microseconds>(end_time_int - start_time_int)};

    // Đo thời gian thực thi hàm strReverse
    auto start_time_str{std::chrono::high_resolution_clock::now()};
    for (int i{0}; i < num_iterations; i++) {
        strReverse(i);
    }
    auto end_time_str{std::chrono::high_resolution_clock::now()};
    auto duration_str{std::chrono::duration_cast<std::chrono::microseconds>(end_time_str - start_time_str)};

    // In kết quả so sánh
    std::cout << "Thoi gian thuc thi intReverse: " << duration_int.count() << " microseconds" << std::endl;
    std::cout << "Thoi gian thuc thi strReverse: " << duration_str.count() << " microseconds" << std::endl;

    return 0;
}
