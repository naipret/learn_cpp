#include <iostream>

int main() {
    double diemHeSoMot_1{}, diemHeSoMot_2{}, diemHeSoHai{}, diemHeSoBa{};
    std::cin >> diemHeSoMot_1 >> diemHeSoMot_2 >> diemHeSoHai >> diemHeSoBa;

    double diemTrungBinh{((diemHeSoMot_1 + diemHeSoMot_2) + (diemHeSoHai * 2.0) + (diemHeSoBa * 3.0)) / 7.0};

    if (diemTrungBinh >= 8) {
        std::cout << "GIOI";
    } else if (diemTrungBinh >= 6.5) {
        std::cout << "KHA";
    } else if (diemTrungBinh >= 5) {
        std::cout << "TRUNG BINH";
    } else {
        std::cout << "YEU";
    }

    return 0;
}
