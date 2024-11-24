#include <iostream>

int stringToInteger(char temp) {
    return (char(temp) - 48);
}

int sumAb(const int temp) {
    if (temp < 10) {
        return temp;
    } else {
        // return (temp / 10) + (temp - ((temp / 10) * 10));
        //! bị quên cái % : chia lấy phần dư=)))
        return (temp / 10) + (temp % 10);
    }
}

int main() {
    std::string SIN;
    while (true) {
        std::cout << "SIN (0 de thoat): ";
        std::cin >> SIN;
        if (SIN == "0") {
            break;
        }
        if (SIN.length() != 9) {
            std::cout << "SIN khong hop le!" << std::endl;
            continue;
        }
        int s1 = stringToInteger(SIN[0]) + stringToInteger(SIN[2]) + stringToInteger(SIN[4]) + stringToInteger(SIN[6]);
        int s2 = sumAb(stringToInteger(SIN[1]) * 2) + sumAb(stringToInteger(SIN[3]) * 2) + sumAb(stringToInteger(SIN[5]) * 2) + sumAb(stringToInteger(SIN[7]) * 2);
        const double checkDbl{(s1 + s2 + stringToInteger(SIN[8])) / 10.0};
        const int checkInt{(s1 + s2 + stringToInteger(SIN[8])) / 10};
        if (checkDbl == (checkInt * 1.0)) {
            std::cout << "SIN hop le!" << std::endl;
        } else {
            std::cout << "SIN khong hop le!" << std::endl;
        }
    }
    return 0;
}
