#include <iostream>
#include <cmath>  //to use the pi number

int main() {
    //* diện tích: area
    //* thể tích: volume = 4/3𝝅r3
    //* bán kính: radius
    std::cout << "Nhập diện tích S: ";
    double area { };
    std::cin >> area;
    double radius { sqrt(area / (4 * M_PI)) };  // area = 4𝝅r2
    std::cout << "Thể tích V = " << 4.0 / 3 * M_PI * pow(radius, 3) << std::endl;
    return 0;
}
