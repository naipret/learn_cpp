#include <cmath>
#include <iostream>

#include "../../include/vector_maths.hpp"

//! i dont need this function anymore because it was re-created in
//! "include/custom_functions.h"
// double vector_length(double xI, double yI, double xM, double yM) {
//     return sqrt(pow(xM - xI, 2) + pow(yM - yI, 2));
// }

int main() {
    double xC{}, yC{}, R{}, xM{}, yM{};
    std::cout << "Nhap toa do tam C(xC, yC)? ";
    std::cin >> xC >> yC;
    std::cout << "Nhap ban kinh R? ";
    std::cin >> R;
    std::cout << "Nhap toa do diem M(xM, yM)? ";
    std::cin >> xM >> yM;
    double IM{twoPointVectorLength(xC, yC, xM, yM)};
    if (R == IM)
        std::cout << "M nam tren C()" << std::endl;
    else if (R > IM)
        std::cout << "M nam trong C()" << std::endl;
    else if (R < IM)
        std::cout << "M nam ngoai C()" << std::endl;
    return 0;
}
