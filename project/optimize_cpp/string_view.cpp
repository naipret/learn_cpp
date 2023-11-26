#include <iostream>
#include <string>
#include <string_view>

void printStringView(std::string_view strView) {
    std::cout << "String View: " << strView << "\n";
}

int main() {

    // Tạo chuỗi std::string
    std::string str = "Hello, World!";

    // Tạo string_view từ chuỗi std::string
    std::string_view strv(str);

    // Sử dụng string_view
    printStringView(strv);

    // Cắt chuỗi
    std::string_view subStringView = strv.substr(0, 5);
    printStringView(subStringView);

    // Sử dụng chuỗi std::string
    std::string modifiedStr = std::string(strv) + " Welcome!";
    std::cout << "Modified String: " << modifiedStr << "\n";

    return 0;
}
