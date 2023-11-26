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

    // Yêu cầu người dùng nhập họ và tên
    std::string firstName, lastName;
    std::cout << "Nhập họ của bạn: ";
    std::getline(std::cin >> std::ws, firstName);

    std::cout << "Nhập tên của bạn: ";
    std::getline(std::cin >> std::ws, lastName);

    // In ra họ và tên
    std::cout << "Xin chào, " << firstName << " " << lastName << "!" << std::endl;



    // Khởi tạo chuỗi
    std::string str = "Hello, C++ Strings!";

    // Sử dụng hàm append() để thêm chuỗi
    str.append(" Welcome!");

    // In ra chuỗi
    std::cout << "Chuỗi sau khi thêm: " << str << std::endl;

    // Sử dụng hàm length() để lấy độ dài chuỗi
    std::cout << "Độ dài của chuỗi: " << str.length() << std::endl;

    // Sử dụng hàm substr() để cắt chuỗi
    std::string substring = str.substr(7, 5);  // Lấy phần "C++"
    std::cout << "Chuỗi con: " << substring << std::endl;

    // Sử dụng hàm find() để tìm vị trí xuất hiện đầu tiên của một chuỗi con
    size_t found = str.find("C++");
    if (found != std::string::npos) {
        std::cout << "Chuỗi con 'C++' xuất hiện ở vị trí: " << found << std::endl;
    } else {
        std::cout << "Không tìm thấy chuỗi con 'C++'" << std::endl;
    }

    // Sử dụng hàm replace() để thay thế chuỗi con
    str.replace(found, 3, "CPP");
    std::cout << "Chuỗi sau khi thay thế: " << str << std::endl;

    return 0;
}
