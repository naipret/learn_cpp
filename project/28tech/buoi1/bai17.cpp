#include <iostream>

int isFebruarySpecialYear(int &n) {
    if ((n % 400 == 0) || ((n % 4 == 0) && (n % 100 != 1))) {
        return 29;
    }
    return 28;
}

int main() {
    int t{}, n{};
    std::cin >> t >> n;

    if (t <= 0 || n <= 0) {
        std::cout << "INVALID";
        return 0;
    }
    if (t > 12) {
        std::cout << "INVALID";
        return 0;
    }
    switch (t) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            std::cout << 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << 30;
            break;
        case 2:
            std::cout << isFebruarySpecialYear(n);
            break;
        default:
            std::cout << "INVALID";
            return 0;
            break;
    }
    
    return 0;
}
