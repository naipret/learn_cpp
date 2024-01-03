#include <stdlib.h>  // to use system("clear");

#include <iostream>

void pressEnter() {
    std::cout << std::endl;
    std::cout << "Nhan \"ENTER\" de tiep tuc! ";
    std::string enter{};
    getline(std::cin, enter);
    std::cout << std::endl;
}

// % tree
// .
// ├── build121
// │   └── foo
// ├── build-64
// │   └── foo
// └── buildtools
//     └── test.txt

int main() {
    system("clear");

    //! __ 0. IOSTREAM __

    std::cout << "A. Co nhung gi trong thu vien \"IOSTREAM\":D\n";
    std::cout << "|-- 1. ISTREAM (input stream):  Thu vien chung dung de \"NHAP\" du lieu gi do\n";
    std::cout << "|-- 2. OSTREAM (output stream): Thu vien chung dung de \"XUAT\" du lieu gi do\n";
    std::cout << "|-- 3. IOSFWD (input-output stream forward) : Dung cho cac khai bao chuyen tiep (forward declaration)\n";
    std::cout << "|-- 4. IOS (base cua IOSTREAM)\n";
    // Cai nay co the duoc giai thich nhu khi minh co mot project co nhieu file a
    // Co main.cpp | function.h <include> | function.cpp <src>
    // Thi cai thang IOS nhu la src
    std::cout << "|-- 5. STREAMBUF (stream buffer) : ... ko quan tam=)))\n";
    pressEnter();

    //! __ 1. ISTREAM __

    std::cout << "1. Trong ISTREAM co gi\n";

    //* _ 1.1. Toan tu >> : Dung de nhap xuat do _
    std::cout << "|-- 1.1. Toan tu \">>\" : Dung trong nhap du lieu ay\n";
    std::cout << "|   |-- Vd tieu bieu : std::cin \\=)))\n";
    std::cout << "|[*]    |-- NHAP vao cai gi do di -> ";
    std::string s_1_1{};
    std::cin >> s_1_1;
    // std::cout << "\n";
    std::cout << "|-- 1.2. ";

    // 2. gcount : Get character count (Lay ki tu chu cai duoc input)
    // std::cout <<
}

// https://cplusplus.com/reference/istream/istream/
