#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // Tạo vector mẫu
    std::vector<int> source = {1, 2, 3, 4, 5};

    // 1. copy: Copy range of elements
    std::vector<int> copyDestination(source.size());
    std::copy(source.begin(), source.end(), copyDestination.begin());

    // In vector sau khi copy
    std::cout << "1. Copy Destination:";
    for (const auto& num : copyDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 2. copy_n: Copy elements
    std::vector<int> copyNDestination(3);
    std::copy_n(source.begin(), 3, copyNDestination.begin());

    // In vector sau khi copy_n
    std::cout << "2. Copy_n Destination:";
    for (const auto& num : copyNDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 3. copy_if: Copy certain elements of range
    std::vector<int> copyIfDestination(source.size());
    std::copy_if(source.begin(), source.end(), copyIfDestination.begin(), [](int num) { return num % 2 == 0; });

    // In vector sau khi copy_if
    std::cout << "3. Copy_if Destination:";
    for (const auto& num : copyIfDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 4. copy_backward: Copy range of elements backward
    std::vector<int> copyBackwardDestination(source.size());
    std::copy_backward(source.begin(), source.end(), copyBackwardDestination.end());

    // In vector sau khi copy_backward
    std::cout << "4. Copy_backward Destination:";
    for (const auto& num : copyBackwardDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 5. move: Move range of elements
    std::vector<int> moveDestination(source.size());
    std::move(source.begin(), source.end(), moveDestination.begin());

    // In vector sau khi move
    std::cout << "5. Move Destination:";
    for (const auto& num : moveDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 6. move_backward: Move range of elements backward
    std::vector<int> moveBackwardDestination(source.size());
    std::move_backward(source.begin(), source.end(), moveBackwardDestination.end());

    // In vector sau khi move_backward
    std::cout << "6. Move_backward Destination:";
    for (const auto& num : moveBackwardDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 7. swap: Exchange values of two objects
    int a = 10, b = 20;
    std::swap(a, b);
    std::cout << "7. Swap values: a = " << a << ", b = " << b << std::endl;

    // 8. swap_ranges: Exchange values of two ranges
    std::vector<int> swapRangeSource1 = {1, 2, 3};
    std::vector<int> swapRangeSource2 = {4, 5, 6};
    std::swap_ranges(swapRangeSource1.begin(), swapRangeSource1.end(), swapRangeSource2.begin());

    // In vector sau khi swap_ranges
    std::cout << "8. Swap_ranges Source1:";
    for (const auto& num : swapRangeSource1) {
        std::cout << " " << num;
    }
    std::cout << std::endl;
    std::cout << "   Swap_ranges Source2:";
    for (const auto& num : swapRangeSource2) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 9. iter_swap: Exchange values of objects pointed to by two iterators
    std::vector<int>::iterator iter1 = source.begin();
    std::vector<int>::iterator iter2 = source.begin() + 2;
    std::iter_swap(iter1, iter2);

    // In vector sau khi iter_swap
    std::cout << "9. iter_swap Destination:";
    for (const auto& num : source) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 10. transform: Transform range
    std::vector<int> transformSource = {1, 2, 3, 4, 5};
    std::vector<int> transformDestination(transformSource.size());
    std::transform(transformSource.begin(), transformSource.end(), transformDestination.begin(), [](int num) {
        return num * 2;
    });

    // In vector sau khi transform
    std::cout << "10. Transform Destination:";
    for (const auto& num : transformDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 11. replace: Replace value in range
    std::vector<int> replaceVector = {1, 2, 3, 4, 5};
    std::replace(replaceVector.begin(), replaceVector.end(), 3, 10);

    // In vector sau khi replace
    std::cout << "11. Replace Vector:";
    for (const auto& num : replaceVector) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 12. replace_if: Replace values in range
    std::vector<int> replaceIfVector = {1, 2, 3, 4, 5};
    std::replace_if(
        replaceIfVector.begin(), replaceIfVector.end(), [](int num) { return num % 2 == 0; }, 0);

    // In vector sau khi replace_if
    std::cout << "12. Replace_if Vector:";
    for (const auto& num : replaceIfVector) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 13. replace_copy: Copy range replacing value
    std::vector<int> replaceCopySource = {1, 2, 3, 4, 5};
    std::vector<int> replaceCopyDestination(replaceCopySource.size());
    std::replace_copy(replaceCopySource.begin(), replaceCopySource.end(), replaceCopyDestination.begin(), 3, 10);

    // In vector sau khi replace_copy
    std::cout << "13. Replace_copy Destination:";
    for (const auto& num : replaceCopyDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 14. replace_copy_if: Copy range replacing value
    std::vector<int> replaceCopyIfSource = {1, 2, 3, 4, 5};
    std::vector<int> replaceCopyIfDestination(replaceCopyIfSource.size());
    std::replace_copy_if(
        replaceCopyIfSource.begin(), replaceCopyIfSource.end(), replaceCopyIfDestination.begin(),
        [](int num) { return num % 2 == 0; }, 0);

    // In vector sau khi replace_copy_if
    std::cout << "14. Replace_copy_if Destination:";
    for (const auto& num : replaceCopyIfDestination) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 15. fill: Fill range with value
    std::vector<int> fillVector(5);
    std::fill(fillVector.begin(), fillVector.end(), 7);

    // In vector sau khi fill
    std::cout << "15. Fill Vector:";
    for (const auto& num : fillVector) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    // 16. fill_n: Fill sequence with value
    std::vector<int> fillNVector(5);
    std::fill_n(fillNVector.begin(), 3, 5);

    // In vector sau khi fill_n
    std::cout << "16. Fill_n Vector:";
    for (const auto& num : fillNVector) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
