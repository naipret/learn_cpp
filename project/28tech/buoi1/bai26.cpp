#include <iostream>

std::string triangleType(const double &a, const double &b, const double &c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            return "Tam giac deu";
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
    int a{}, b{}, c{};
    std::cin >> a >> b >> c;

    std::cout << triangleType(a, b, c);

    return 0;
}
