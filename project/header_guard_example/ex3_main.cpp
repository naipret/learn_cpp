#include <cmath>
#include <iostream>

#include "vector_maths.hpp"

int main() {
    double xC{}, yC{}, R{}, xM{}, yM{};
    std::cout << "Nhap toa do tam C(xC, yC)? ";
    std::cin >> xC >> yC;
    std::cout << "Nhap ban kinh R? ";
    std::cin >> R;
    std::cout << "Nhap toa do diem M(xM, yM)? ";
    std::cin >> xM >> yM;

    double IM{cst::vectorLength(xC, yC, xM, yM)};

    if (R == IM)
        std::cout << "M nam tren C()" << std::endl;
    else if (R > IM)
        std::cout << "M nam trong C()" << std::endl;
    else if (R < IM)
        std::cout << "M nam ngoai C()" << std::endl;
    return 0;
}

//! HOW TO COMPILE
//! example: C:\msys64\ucrt64\bin\g++.exe -Wall -Wextra -Wpedantic -fdiagnostics-color=always -g D:\Code\learn_cpp\project\header_guard_example\ex3_main.cpp -ID:\Code\learn_cpp\include\ D:\Code\learn_cpp\src\vector_maths.cpp -o D:\Code\learn_cpp\bin\ex3_main.exe
