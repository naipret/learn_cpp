#include <iostream>
#include <string>

int main() {
    
    // Khai báo và khởi tạo chuỗi
    std::string greeting = "Hello, ";

    // Nối chuỗi
    greeting += "World!";

    // In ra kết quả
    std::cout << greeting << std::endl;

    // Truy cập từng ký tự trong chuỗi
    for (char ch : greeting) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;

    // Chiều dài của chuỗi
    std::cout << "Độ dài của chuỗi: " << greeting.length() << std::endl;

    // So sánh chuỗi
    std::string otherGreeting = "Hello, World!";
    if (greeting == otherGreeting) {
        std::cout << "Hai chuỗi giống nhau." << std::endl;
    } else {
        std::cout << "Hai chuỗi khác nhau." << std::endl;
    }

    return 0;
}
