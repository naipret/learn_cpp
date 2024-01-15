#include <algorithm>
#include <iostream>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    // 1. all_of
    std::cout << "Kiểm tra xem tất cả các phần tử có lớn hơn 0 hay không: ";
    if (std::all_of(numbers, numbers + 5, [](int num) { return num > 0; })) {
        std::cout << "Tất cả các phần tử đều lớn hơn 0." << std::endl;
    } else {
        std::cout << "Không phải tất cả các phần tử đều lớn hơn 0." << std::endl;
    }

    // 2. any_of
    std::cout << "Kiểm tra xem có phần tử nào chẵn hay không: ";
    if (std::any_of(numbers, numbers + 5, [](int num) { return num % 2 == 0; })) {
        std::cout << "Có ít nhất một phần tử chẵn." << std::endl;
    } else {
        std::cout << "Không có phần tử chẵn nào." << std::endl;
    }

    // 3. none_of
    std::cout << "Kiểm tra xem không có phần tử nào chẵn hay không: ";
    if (std::none_of(numbers, numbers + 5, [](int num) { return num % 2 == 0; })) {
        std::cout << "Tất cả các phần tử đều lẻ." << std::endl;
    } else {
        std::cout << "Có ít nhất một phần tử chẵn." << std::endl;
    }

    // 4. for_each
    std::cout << "In ra bình phương của mỗi phần tử: ";
    std::for_each(numbers, numbers + 5, [](int num) { std::cout << num * num << " "; });
    std::cout << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 5. adjacent_find
    std::cout << "Tìm cặp phần tử liền kề đầu tiên có giá trị bằng nhau: ";
    int *it = std::adjacent_find(numbers, numbers + 6);
    if (it != numbers + 6) {
        std::cout << *it << " " << *(it + 1) << std::endl;
    } else {
        std::cout << "Không có cặp phần tử liền kề nào có giá trị bằng nhau." << std::endl;
    }

    // 6. mismatch
    std::cout << "Tìm vị trí đầu tiên mà hai mảng khác nhau: ";
    auto result = std::mismatch(numbers, numbers + 5, numbers + 5);
    if (result.first != numbers + 5) {
        std::cout << (result.first - numbers) << std::endl;
        std::cout << "Các phần tử khác nhau là: " << *result.first << " " << *result.second << std::endl;
    } else {
        std::cout << "Hai mảng giống nhau." << std::endl;
    }

    // 7. equal
    std::cout << "Kiểm tra xem hai mảng có bằng nhau hay không: ";
    if (std::equal(numbers, numbers + 5, numbers + 5)) {
        std::cout << "Hai mảng bằng nhau." << std::endl;
    } else {
        std::cout << "Hai mảng không bằng nhau." << std::endl;
    }

    // 8. is_permutation
    std::cout << "Kiểm tra xem hai mảng có phải là hoán vị của nhau hay không: ";
    if (std::is_permutation(numbers, numbers + 5, numbers + 5)) {
        std::cout << "Hai mảng là hoán vị của nhau." << std::endl;
    } else {
        std::cout << "Hai mảng không phải là hoán vị của nhau." << std::endl;
    }

    return 0;
}
