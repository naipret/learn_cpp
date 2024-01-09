#include <iostream>
#include <vector>

int main() {
    // Tạo một std::vector với kiểu dữ liệu int
    std::vector<int> myVector;

    // Chèn các phần tử vào std::vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Duyệt qua toàn bộ std::vector và in ra các phần tử
    std::cout << "Contents of the vector:" << std::endl;
    for (const int& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Kiểm tra kích thước của std::vector
    std::cout << "Size of the vector: " << myVector.size() << std::endl;

    // Truy cập phần tử tại một vị trí cụ thể
    std::cout << "Element at index 1: " << myVector[1] << std::endl;

    // Thay đổi giá trị của một phần tử
    myVector[1] = 25;

    // In ra std::vector sau khi thay đổi
    std::cout << "Contents of the vector after modification:" << std::endl;
    for (const int& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Xóa phần tử cuối cùng từ std::vector
    myVector.pop_back();

    // In ra std::vector sau khi xóa
    std::cout << "Contents of the vector after popping back:" << std::endl;
    for (const int& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
