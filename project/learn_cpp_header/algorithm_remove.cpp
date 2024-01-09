#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Tạo vector mẫu
    std::vector<int> source = {1, 2, 2, 3, 4, 4, 5, 5, 5};

    // 1. remove: Remove value from range
    std::vector<int>::iterator removeIter = std::remove(source.begin(), source.end(), 4);
    source.erase(removeIter, source.end());

    // In vector sau khi remove
    std::cout << "1. Remove Vector:";
    for (const auto& num : source) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 2. remove_if: Remove elements from range
    std::vector<int> removeIfVector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator removeIfIter =
        std::remove_if(removeIfVector.begin(), removeIfVector.end(), [](int num) { return num % 2 == 0; });
    removeIfVector.erase(removeIfIter, removeIfVector.end());

    // In vector sau khi remove_if
    std::cout << "2. Remove_if Vector:";
    for (const auto& num : removeIfVector) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 3. remove_copy: Copy range removing value
    std::vector<int> removeCopySource = {1, 2, 2, 3, 4, 4, 5, 5, 5};
    std::vector<int> removeCopyDestination(removeCopySource.size());
    std::remove_copy(removeCopySource.begin(), removeCopySource.end(), removeCopyDestination.begin(), 4);

    // In vector sau khi remove_copy
    std::cout << "3. Remove_copy Destination:";
    for (const auto& num : removeCopyDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 4. remove_copy_if: Copy range removing values
    std::vector<int> removeCopyIfSource = {1, 2, 3, 4, 5};
    std::vector<int> removeCopyIfDestination(removeCopyIfSource.size());
    std::remove_copy_if(removeCopyIfSource.begin(), removeCopyIfSource.end(), removeCopyIfDestination.begin(),
                        [](int num) { return num % 2 == 0; });

    // In vector sau khi remove_copy_if
    std::cout << "4. Remove_copy_if Destination:";
    for (const auto& num : removeCopyIfDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 5. unique: Remove consecutive duplicates in range
    std::vector<int> uniqueVector = {1, 1, 2, 2, 3, 4, 4, 5};
    std::vector<int>::iterator uniqueIter = std::unique(uniqueVector.begin(), uniqueVector.end());
    uniqueVector.erase(uniqueIter, uniqueVector.end());

    // In vector sau khi unique
    std::cout << "5. Unique Vector:";
    for (const auto& num : uniqueVector) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 6. unique_copy: Copy range removing duplicates
    std::vector<int> uniqueCopySource = {1, 1, 2, 2, 3, 4, 4, 5};
    std::vector<int> uniqueCopyDestination(uniqueCopySource.size());
    std::unique_copy(uniqueCopySource.begin(), uniqueCopySource.end(), uniqueCopyDestination.begin());

    // In vector sau khi unique_copy
    std::cout << "6. Unique_copy Destination:";
    for (const auto& num : uniqueCopyDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
