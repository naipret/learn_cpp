#include <cmath>
#include <iostream>

double vectorLength(const double &xI, const double &yI, const double &xM, const double &yM) {
    return sqrt(pow(xM - xI, 2.0) + pow(yM - yI, 2.0)); // kiến thức toán 10 sgk mới
}

int main() {
    double xC{}, yC{}, R{}, xM{}, yM{};
    std::cout << "Nhap toa do tam C(xC, yC)? ";
    std::cin >> xC >> yC;
    std::cout << "Nhap ban kinh R? ";
    std::cin >> R;
    std::cout << "Nhap toa do diem M(xM, yM)? ";
    std::cin >> xM >> yM;

    const double lengthIM{vectorLength(xC, yC, xM, yM)};

    if (R == lengthIM)
        std::cout << "M nam tren C()" << std::endl;
    else if (R > lengthIM)
        std::cout << "M nam trong C()" << std::endl;
    else if (R < lengthIM)
        std::cout << "M nam ngoai C()" << std::endl;
    return 0;
}
