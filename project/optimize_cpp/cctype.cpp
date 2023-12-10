#include <cctype>
#include <iostream>

bool isSpecialCharacter(char ch) {
    return !std::isalnum(ch) && !std::isspace(ch);
}

int main() {
    std::string inputString;

    std::cout << "Nhap mot chuoi ky tu: ";
    std::getline(std::cin >> std::ws, inputString);

    for (char ch : inputString) {
        if (std::isalnum(ch)) {
            std::cout << ch << " vua la mot chu cai hoac so." << std::endl;
        }
        if (std::isalpha(ch)) {
            std::cout << ch << " la mot chu cai." << std::endl;
        } else if (std::isdigit(ch)) {
            std::cout << ch << " la mot chu so." << std::endl;
        } else if (std::isspace(ch)) {
            std::cout << ch << " la mot khoang trang." << std::endl;
        } else if (isSpecialCharacter(ch)) {
            std::cout << ch << " la mot ky tu dac biet." << std::endl;
        } else {
            std::cout << ch << " khong thuoc cac loai kieu tren." << std::endl;
        }
    }

    return 0;
}
