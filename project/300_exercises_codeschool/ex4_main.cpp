#include <cmath>  // để sài hàm tính căn bậc 2 "sqrt()"
#include <iostream>

std::string triangleType(const double &a, const double &b, const double &c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            return "Tam giac deu";
        } else if (((a * a == b * b + c * c) && (b == c)) || ((b * b == a * a + c * c) && (a == c)) ||
                   ((c * c == a * a + b * b) && (a == b))) {
            return "Tam giac vuong can";
        } else if (a == b || a == c || b == c) {
            return "Tam giac can";
        } else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
            return "Tam giac vuong";
        } else {
            return "Tam giac thuong";
        }
    } else {
        return "Khong phai la tam giac";
    }
}

int main() {
    double a{}, b{}, c{};
    std::cout << "Nhap 3 canh cua tam giac: ";
    std::cin >> a >> b >> c;

    std::cout << triangleType(a, b, c) << std::endl;

    const double p{(a + b + c) / 2.0};
    const double S{sqrt(p * (p - a) * (p - b) * (p - c))}; // công thức Heron toán 10 sgk mới
    std::cout << "Dien tich S = " << S << std::endl;
    return 0;
}
