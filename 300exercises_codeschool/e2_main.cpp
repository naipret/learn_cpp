#include <cmath>
#include <iostream>

int main() {
    double xA { }, xB { }, yA { }, yB { };
    std::cout << "A(xA, yA)? ";
    std::cin >> xA >> yA;
    std::cout << "A(xB, yB)? ";
    std::cin >> xB >> yB;
    double length_AB { sqrt(pow(xB - xA, 2) + pow(yB - yA, 2)) };
    std::cout << "|AB| = " << length_AB << std::endl;
    return 0;
}