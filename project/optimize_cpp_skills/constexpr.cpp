#include <iostream>

// Hàm constexpr có thể được sử dụng để tính toán giá trị tại thời điểm biên dịch
constexpr int square(int x) {
    return x * x;
}

int main() {
    
    // Biến được khai báo với constexpr và giá trị được tính toán tại thời điểm biên dịch
    constexpr int side = 5;
    constexpr int area = square(side);

    // In ra kết quả
    std::cout << "Diện tích hình vuông có cạnh " << side << " là: " << area << std::endl;

    return 0;
}
