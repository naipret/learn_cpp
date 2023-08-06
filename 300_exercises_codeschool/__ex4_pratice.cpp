#include <iostream>
// #include <stdlib.h> // to use system("clear");

int main() {
    // system("clear");
    std::string password{};
    bool first_input{true};
    do {
        if (first_input) {
            std::cout << "Cac yeu cau cua mot mat khau manh:\n";
            std::cout << "+ Co it nhat 10 ky tu\n";
            std::cout << "+ Co ky tu viet hoa (1)\n";
            std::cout << "+ Co ky tu viet thuong (2)\n";
            std::cout << "Vui long nhap mat khau: ";
            // std::cout << std::flush;
            getline(std::cin, password);
            // std::cout << std::flush;
            first_input = false;
        } else {
            std::cout << "Mat khau khong dat yeu cau!\n";
            std::cout << "Vui long nhap lai: ";
            // std::cout << std::flush;
            getline(std::cin, password);
        }
    } while (password.length() < 10);
}
