#include <iostream>

int main() {
    int n{};
    std::cin >> n;

    if (n <= 0) {
        std::cout << "INVALID";
        return 0;
    }
    if ((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 1))) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    
    return 0;
}
