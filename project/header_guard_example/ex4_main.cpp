#include <cmath>  //to use sqrt()
#include <iostream>

#include "cst_triangle_type.hpp"

int main() {
    double a{}, b{}, c{};
    std::cout << "Nhap 3 canh cua tam giac: ";
    std::cin >> a >> b >> c;

    std::cout << cst::triangleType(a, b, c) << std::endl;

    double p{(a + b + c) / 2.0};
    double S{sqrt(p * (p - a) * (p - b) * (p - c))};
    std::cout << "Dien tich S = " << S << std::endl;
    return 0;
}

//! HOW TO COMPILE
//! example: C:\msys64\ucrt64\bin\g++.exe -Wall -Wextra -Wpedantic -fdiagnostics-color=always -g D:\Code\learn_cpp\project\header_guard_example\ex4_main.cpp -ID:\Code\learn_cpp\include\ D:\Code\learn_cpp\src\cst_triangle_type.cpp -o D:\Code\learn_cpp\bin\ex4_main.exe
