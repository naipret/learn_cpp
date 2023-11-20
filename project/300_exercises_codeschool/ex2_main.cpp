#include <cmath> // để sài hàm tính mũ "pow()"
#include <iostream>

int main() {
    double xA{}, xB{}, yA{}, yB{};
    std::cout << "A(xA, yA)? ";
    std::cin >> xA >> yA;
    std::cout << "A(xB, yB)? ";
    std::cin >> xB >> yB;
    // Hàm pow(a, n) thuộc thư viện <cmath> (cmath là của c++, còn math.h là của c)
    // Trong đó a là cơ số, n là số mũ
    // Còn nhiều hàm trong <cmath> cũng hay lắm á
    const double length_AB{sqrt(pow(xB - xA, 2.0) + pow(yB - yA, 2.0))}; // toán 10 sgk mới
    std::cout << "|AB| = " << length_AB << std::endl;
    return 0;
}
