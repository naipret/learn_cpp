// output ví dụ trong đề sai

#include <iostream>

int main() {
    int ngay{};
    std::cin >> ngay;

    int nam{ngay / 360};
    int thang{(ngay - (nam * 360)) / 30};
    int ngayConLai{ngay - (nam * 360) - (thang * 30)};
    std::cout << nam << ' ' << thang << ' ' << ngayConLai;

    return 0;
}
