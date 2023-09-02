#include <cmath>  //to use the pi number M_PI
#include <iostream>

int main() {
    //* dien tich: area
    //* the tich : volume = 4/3𝝅r^3
    //* ban kinh : radius
    std::cout << "Nhap dien tich S: ";
    double area{};
    std::cin >> area;
    double radius{sqrt(area / (4 * M_PI))};  // area = 4𝝅r^2
    std::cout << "The tich V = " << 4.0 / 3 * M_PI * pow(radius, 3)
              << std::endl;
    return 0;
}
