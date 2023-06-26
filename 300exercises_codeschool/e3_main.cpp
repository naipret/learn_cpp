#include <iostream>
#include <cmath>

double vector_length(double xI, double yI, double xM, double yM) {
    return sqrt(pow(xM - xI, 2) + pow(yM - yI, 2));
}

int main() {
    double xC { }, yC { }, R { }, xM { }, yM { };
    std::cout << "Nhập toạ độ tâm C(xC, yC)? ";
    std::cin >> xC >> yC;
    std::cout << "Nhập bán kính R? ";
    std::cin >> R;
    std::cout << "Nhập toạ đọ điểm M(xM, yM)? ";
    std::cin >> xM >> yM;
    double IM { vector_length(xC, yC, xM, yM) };
    if (R == IM) std::cout << "M nằm trên C()";
    else if (R > IM) std::cout << "M nằm trong C()";
    else if (R < IM) std::cout << "M nằm ngoài C()";
    return 0;
}