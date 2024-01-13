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

// 1. **Hàm Kiểm tra:**
//   - `isalpha`: Kiểm tra xem một ký tự có phải là chữ cái không.
//   - `isdigit`: Kiểm tra xem một ký tự có phải là chữ số không.
//   - `isalnum`: Kiểm tra xem một ký tự có phải là chữ cái hoặc chữ số không.
//   - `islower`, `isupper`: Kiểm tra xem một ký tự có phải là chữ thường hay chữ hoa không.

// 2. **Hàm Chuyển đổi:**
//   - `tolower`: Chuyển đổi một ký tự thành chữ thường.
//   - `toupper`: Chuyển đổi một ký tự thành chữ hoa.

// 3. **Hàm Kiểm tra ký tự đặc biệt:**
//   - `isspace`: Kiểm tra xem một ký tự có phải là khoảng trắng không.
//   - `iscntrl`: Kiểm tra xem một ký tự có phải là ký tự điều khiển không.

// 4. **Hàm Kiểm tra chữ viết tắt:**
//   - `isxdigit`: Kiểm tra xem một ký tự có phải là số thập lục phân không.
