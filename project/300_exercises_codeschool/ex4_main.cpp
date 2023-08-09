#include <cmath>  //to use sqrt()
#include <iostream>

#include "..\include\triangle_type.h"

int main() {
    double a{}, b{}, c{};
    std::cout << "Nhap 3 canh cua tam giac: ";
    std::cin >> a >> b >> c;

    // check triangle type
    // if (a + b > c && a + c > b && b + c > a) {
    //     if (a == b && b == c) {
    //         std::cout << "Tam giac deu" << std::endl;
    //     } else if (((a * a == b * b + c * c) && (b == c)) || ((b * b == a * a + c * c) && (a == c)) ||
    //                ((c * c == a * a + b * b) && (a == b))) {
    //         std::cout << "Tam giac vuong can" << std::endl;
    //     } else if (a == b || a == c || b == c) {
    //         std::cout << "Tam giac can" << std::endl;
    //     } else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
    //         std::cout << "Tam giac vuong" << std::endl;
    //     } else {
    //         std::cout << "Tam giac thuon" << std::endl;
    //     }
    // } else {
    //     std::cout << "Khong phai la tam giac" << std::endl;
    // }

    std::cout << triangle_type(a, b, c) << std::endl;

    double p{(a + b + c) / 2.0};
    double S{sqrt(p * (p - a) * (p - b) * (p - c))};
    std::cout << "Dien tich S = " << S << std::endl;
    return 0;
}
