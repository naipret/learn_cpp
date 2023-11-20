#include <cmath>
#include <iostream>

int main() {
    int minute{};
    std::cout << "Nhap so do x cua goc (phut): ";
    std::cin >> minute;
    double degree{double(minute) / 60.0};
    while (degree > 360) {
        degree -= 360;
    }
    int quadrant{};
    if (0 <= degree && degree < 90) {
        quadrant = 1;
    } else if (90 <= degree && degree < 180) {
        quadrant = 2;
    } else if (180 <= degree && degree < 270) {
        quadrant = 3;
    } else {
        quadrant = 4;
    }
    std::cout << "x thuoc goc phan tu thu: " << quadrant << "\n";
    std::cout << "cos(x) = " << cos(degree * M_PI / 180.0);
    return 0;
}
