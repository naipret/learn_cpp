#include <iomanip>
#include <iostream>

int main() {
    int a{}, b{};
    std::cin >> a >> b;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    std::cout << a + b << " " << a - b << " " << a * b << " " << (a * 1.0) / (b * 1.0);
    return 0;
}
