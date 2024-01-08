#include <iostream>

int main() {
    int ab, bc, ca;
    std::cin >> ab >> bc >> ca;

    int x{(ab - bc + ca) / 4};
    int y{(ab + bc - ca) / 4};
    int z{(-ab + bc + ca) / 4};

    std::cout << 2 * (x + y + z);

    return 0;
}
