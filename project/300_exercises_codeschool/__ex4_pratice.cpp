#include <stdlib.h>  // to use system("clear");

#include <iostream>

void invalidPassword(std::string &password) {
    std::cout << "Mat khau khong hop le!\n";
    std::cout << "Vui long nhap lai: ";
    getline(std::cin, password);
}

int upperCase(std::string const &password) {
    for (int i = 0; i < password.length(); ++i) {
        if ((char(password[i]) >= 65) && (char(password[i]) <= 90)) {
            return 1;
        }
    }
    return 0;
}

int lowerCase(std::string const &password) {
    for (int i = 0; i < password.length(); ++i) {
        if ((char(password[i]) >= 97) && (char(password[i]) <= 122)) {
            return 1;
        }
    }
    return 0;
}

int numericCase(std::string const &password) {
    for (int i = 0; i < password.length(); ++i) {
        if ((char(password[i]) >= 48) && (char(password[i]) <= 57)) {
            return 1;
        }
    }
    return 0;
}

int specialCase(std::string const &password) {
    for (int i = 0; i < password.length(); ++i) {
        if ((char(password[i]) >= 65) && (char(password[i]) <= 90)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    system("clear");
    std::string password{};
    // bool first_input{true};
    std::cout << "Cac yeu cau cua mot MAT KHAU MANH:\n";
    std::cout << "|-- Co it nhat 10 ky tu\n";
    std::cout << "|-- Co ky tu viet hoa (1)\n";
    std::cout << "|-- Co ky tu viet thuong (2)\n";
    std::cout << "|-- Co ky tu so (3)\n";
    std::cout << "|-- Co ky tu dac biet (4)\n";
    std::cout << std::endl;
    std::cout << "Vui long nhap mat khau: ";
    //! Kien thuc moi: std::cin.ignore(32767, '\n');
    // std::cin.ignore(32767, '\n');
    getline(std::cin, password);
    // first_input = false;
    std::cout << std::endl;
    while (true) {
        if (password.length() < 10) {
            invalidPassword(password);
            std::cout << std::endl;
            // continue;
        }
        int passwordPoint{upperCase(password) + lowerCase(password) + numericCase(password) + specialCase(password)};
        switch (passwordPoint)
        {
        case 4:
        case 3:
            std::cout << "Mat khau MANH";
            break;
        case 2:
        case 1:
            std::cout << "Mat khau YEU";
        default:
            break;
        }
        break;
    }
}
