#include <iostream>
#include <map>

int main() {
    // Tạo một std::map với key là string và value là int
    std::map<std::string, int> myMap;

    // Chèn các phần tử vào std::map
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 22;

    // Duyệt qua toàn bộ std::map và in ra key và value
    std::cout << "Contents of the map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Tìm kiếm và in ra giá trị của một key cụ thể
    std::string searchKey = "Bob";
    auto it = myMap.find(searchKey);
    if (it != myMap.end()) {
        std::cout << "Value for key " << searchKey << ": " << it->second << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found." << std::endl;
    }

    // Xóa một phần tử từ std::map
    std::string removeKey = "Charlie";
    myMap.erase(removeKey);

    // In ra std::map sau khi xóa
    std::cout << "Contents of the map after erasing '" << removeKey << "':" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
