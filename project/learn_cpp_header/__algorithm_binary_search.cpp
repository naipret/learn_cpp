#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> sortedNumbers = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10};

    // binary_search
    int target = 4;
    bool isFound = std::binary_search(sortedNumbers.begin(), sortedNumbers.end(), target);
    std::cout << "Value " << target << (isFound ? " exists" : " does not exist") << " in the sorted sequence." << std::endl;

    // lower_bound
    auto lower = std::lower_bound(sortedNumbers.begin(), sortedNumbers.end(), target);
    std::cout << "Lower bound of " << target << " is at index: " << std::distance(sortedNumbers.begin(), lower) << std::endl;

    // upper_bound
    auto upper = std::upper_bound(sortedNumbers.begin(), sortedNumbers.end(), target);
    std::cout << "Upper bound of " << target << " is at index: " << std::distance(sortedNumbers.begin(), upper) << std::endl;

    // equal_range
    auto range = std::equal_range(sortedNumbers.begin(), sortedNumbers.end(), target);
    std::cout << "Equal range of " << target << " is from index " << std::distance(sortedNumbers.begin(), range.first)
              << " to " << std::distance(sortedNumbers.begin(), range.second - 1) << std::endl;

    return 0;
}
