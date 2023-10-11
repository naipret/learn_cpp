#include <cmath>  // để sài hàm tính căn bậc 2 "sqrt()"
#include <iostream>

std::string triangle_type(double const a, double const b, double const c) {
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

    std::cout << triangle_type(a, b, c) << std::endl;

    double const p{(a + b + c) / 2.0};
    double const S{sqrt(p * (p - a) * (p - b) * (p - c))}; // công thức Heron toán 10 sgk mới
    std::cout << "Dien tich S = " << S << std::endl;
    return 0;
}
