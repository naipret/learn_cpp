#include <algorithm>
#include <iostream>

// Hàm kiểm tra xem một số có lớn hơn 3 không
bool isGreaterThanThree(int x) {
    return x > 3;
}

int main() {
    const int size = 8;
    int numbers[size] = {1, 2, 3, 4, 5, 6, 7, 8};

    // is_partitioned: Kiểm tra xem mảng có được phân vùng hay không
    if (std::is_partitioned(numbers, numbers + size, isGreaterThanThree)) {
        std::cout << "Array is partitioned." << std::endl;
    } else {
        std::cout << "Array is not partitioned." << std::endl;
    }

    std::cout << std::endl;

    // partition: Phân vùng mảng thành hai phần
    // auto partitionPoint = std::partition(numbers, numbers + size, isGreaterThanThree);

    std::cout << "Partitioned array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // stable_partition: Phân vùng mảng thành hai phần với thứ tự ổn định
    std::stable_partition(numbers, numbers + size, isGreaterThanThree);

    std::cout << "Stable Partitioned array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // partition_copy: Sao chép mảng và phân vùng vào hai mảng khác nhau
    int truePartition[size];
    int falsePartition[size];

    auto partitionCopyEnd = std::partition_copy(numbers, numbers + size, truePartition, falsePartition, isGreaterThanThree);

    std::cout << "True Partitioned array: ";
    for (int i = 0; i < partitionCopyEnd.first - truePartition; ++i) {
        std::cout << truePartition[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "False Partitioned array: ";
    for (int i = 0; i < partitionCopyEnd.second - falsePartition; ++i) {
        std::cout << falsePartition[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // partition_point: Lấy điểm phân vùng trong mảng
    auto partitionPointAfterStable = std::partition_point(numbers, numbers + size, isGreaterThanThree);

    std::cout << "Partition point after stable partition: " << *partitionPointAfterStable << std::endl;
    std::cout << std::endl;

    return 0;
}
