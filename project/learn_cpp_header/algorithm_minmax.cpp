#include <algorithm>
#include <iostream>

int main() {
    const int size = 8;
    int numbers[size] = {3, 1, 4, 1, 5, 9, 2, 6};

    // min: Trả về giá trị nhỏ nhất trong mảng
    int minValue = *std::min_element(numbers, numbers + size);
    std::cout << "Minimum value in the array: " << minValue << std::endl;

    // max: Trả về giá trị lớn nhất trong mảng
    int maxValue = *std::max_element(numbers, numbers + size);
    std::cout << "Maximum value in the array: " << maxValue << std::endl;

    // minmax: Trả về cả giá trị nhỏ nhất và lớn nhất trong mảng
    auto minMaxValues = std::minmax_element(numbers, numbers + size);
    std::cout << "Minimum value in the array: " << *minMaxValues.first << std::endl;
    std::cout << "Maximum value in the array: " << *minMaxValues.second << std::endl;

    // min_element: Trả về iterator đến phần tử nhỏ nhất trong mảng
    auto minElementIt = std::min_element(numbers, numbers + size);
    std::cout << "Minimum element in the array is at position " << (minElementIt - numbers) << std::endl;

    // max_element: Trả về iterator đến phần tử lớn nhất trong mảng
    auto maxElementIt = std::max_element(numbers, numbers + size);
    std::cout << "Maximum element in the array is at position " << (maxElementIt - numbers) << std::endl;

    // minmax_element: Trả về iterator đến phần tử nhỏ nhất và lớn nhất trong mảng
    auto minMaxElementIt = std::minmax_element(numbers, numbers + size);
    std::cout << "Minimum element in the array is at position " << (minMaxElementIt.first - numbers) << std::endl;
    std::cout << "Maximum element in the array is at position " << (minMaxElementIt.second - numbers) << std::endl;

    // min: Trả về giá trị nhỏ nhất giữa hai giá trị
    int minValueBetweenTwo = std::min(10, 20);
    std::cout << "Minimum value between 10 and 20: " << minValueBetweenTwo << std::endl;

    // max: Trả về giá trị lớn nhất giữa hai giá trị
    int maxValueBetweenTwo = std::max(10, 20);
    std::cout << "Maximum value between 10 and 20: " << maxValueBetweenTwo << std::endl;

    // minmax: Trả về cả giá trị nhỏ nhất và lớn nhất giữa hai giá trị
    auto minMaxValuesBetweenTwo = std::minmax(10, 20);
    std::cout << "Minimum value between 10 and 20: " << minMaxValuesBetweenTwo.first << std::endl;
    std::cout << "Maximum value between 10 and 20: " << minMaxValuesBetweenTwo.second << std::endl;

    return 0;
}
