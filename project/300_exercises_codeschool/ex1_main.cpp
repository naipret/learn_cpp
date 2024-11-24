#include <cmath>  // để sài hằng số pi cho chính xác "M_PI"
#include <iostream>

int main() {
    //* diện tích: area = 4𝝅r^2
    //* thể tích : volume = 4/3𝝅r^3
    //* bán kính : radius
    std::cout << "Nhap dien tich S: ";
    double area{};
    std::cin >> area;
    const double radius{sqrt(area / (4.0 * M_PI))};
    std::cout << "The tich V = " << 4.0 / 3.0 * M_PI * pow(radius, 3.0)
              << std::endl;
    return 0;
}
