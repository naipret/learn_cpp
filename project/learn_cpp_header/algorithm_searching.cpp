#include <iostream>
#include <algorithm>

int main() {
    const int size = 10;
    int numbers[size] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6};

    // find: Tìm giá trị trong mảng
    auto findResult = std::find(numbers, numbers + size, 3);
    if (findResult != numbers + size) {
        std::cout << "Value 3 found at position " << (findResult - numbers) << std::endl;
    } else {
        std::cout << "Value 3 not found in the array." << std::endl;
    }

    // find_if: Tìm phần tử thỏa mãn điều kiện
    auto findIfResult = std::find_if(numbers, numbers + size, [](int x) { return x > 3; });
    if (findIfResult != numbers + size) {
        std::cout << "First element greater than 3 found at position " << (findIfResult - numbers) << std::endl;
    } else {
        std::cout << "No element greater than 3 found in the array." << std::endl;
    }

    // find_if_not: Tìm phần tử không thỏa mãn điều kiện
    auto findIfNotResult = std::find_if_not(numbers, numbers + size, [](int x) { return x < 3; });
    if (findIfNotResult != numbers + size) {
        std::cout << "First element not less than 3 found at position " << (findIfNotResult - numbers) << std::endl;
    } else {
        std::cout << "All elements are less than 3 in the array." << std::endl;
    }

    // find_end: Tìm dãy con cuối cùng trong mảng
    int subsequence[size] = {3, 4, 5};
    auto findEndResult = std::find_end(numbers, numbers + size, subsequence, subsequence + 3);
    if (findEndResult != numbers + size) {
        std::cout << "Last subsequence found starting at position " << (findEndResult - numbers) << std::endl;
    } else {
        std::cout << "Subsequence not found in the array." << std::endl;
    }

    // find_first_of: Tìm phần tử từ tập hợp trong mảng
    int set[] = {2, 4, 6};
    auto findFirstOfResult = std::find_first_of(numbers, numbers + size, std::begin(set), std::end(set));
    if (findFirstOfResult != numbers + size) {
        std::cout << "First element from set found at position " << (findFirstOfResult - numbers) << std::endl;
    } else {
        std::cout << "No element from set found in the array." << std::endl;
    }

    // adjacent_find: Tìm phần tử giống nhau liền kề
    auto adjacentFindResult = std::adjacent_find(numbers, numbers + size);
    if (adjacentFindResult != numbers + size) {
        std::cout << "First adjacent equal elements found at position " << (adjacentFindResult - numbers) << std::endl;
    } else {
        std::cout << "No adjacent equal elements found in the array." << std::endl;
    }

    // count: Đếm số lần xuất hiện của giá trị trong mảng
    int countValue = std::count(numbers, numbers + size, 3);
    std::cout << "Value 3 appears " << countValue << " times in the array." << std::endl;

    // count_if: Đếm số lần thỏa mãn điều kiện trong mảng
    int countIfValue = std::count_if(numbers, numbers + size, [](int x) { return x > 3; });
    std::cout << "Number of elements greater than 3 in the array: " << countIfValue << std::endl;

    // search: Tìm dãy con trong mảng
    auto searchResult = std::search(numbers, numbers + size, subsequence, subsequence + 3);
    if (searchResult != numbers + size) {
        std::cout << "Subsequence found starting at position " << (searchResult - numbers) << std::endl;
    } else {
        std::cout << "Subsequence not found in the array." << std::endl;
    }

    // search_n: Tìm dãy con có số lần xuất hiện liên tiếp
    auto searchNResult = std::search_n(numbers, numbers + size, 2, 3);
    if (searchNResult != numbers + size) {
        std::cout << "Sequence of 3 found starting at position " << (searchNResult - numbers) << std::endl;
    } else {
        std::cout << "Sequence of 3 not found in the array." << std::endl;
    }

    return 0;
}
