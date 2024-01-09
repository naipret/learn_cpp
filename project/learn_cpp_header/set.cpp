#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

//! Không chứa các phần tử trùng lặp: Mỗi phần tử trong std::set là duy nhất. Nếu bạn thử thêm một phần tử đã tồn tại, nó sẽ không có hiệu lực và tập hợp sẽ không bị thay đổi.
//! Tự động sắp xếp: Các phần tử trong std::set được tự động sắp xếp theo thứ tự tăng dần. Sự tự động sắp xếp này giúp tìm kiếm và truy cập nhanh chóng.
//! Hiệu suất tìm kiếm tốt: Do sắp xếp tự động, std::set cung cấp hiệu suất tìm kiếm tốt, thường có độ phức tạp O(log n) cho các thao tác tìm kiếm, thêm, và xóa.

int main() {
    // Khởi tạo std::set
    std::set<int> mySet;

    // Thêm các phần tử vào std::set
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(1);  // Phần tử trùng lặp, không ảnh hưởng đến std::set

    // In ra các phần tử đã sắp xếp
    std::cout << "Elements in the set: ";
    for (int element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Kiểm tra xem một phần tử có tồn tại trong std::set hay không
    int searchElement = 4;
    auto it = mySet.find(searchElement);
    if (it != mySet.end()) {
        std::cout << searchElement << " found in the set." << std::endl;
    } else {
        std::cout << searchElement << " not found in the set." << std::endl;
    }

    std::set<int> set1 = {1, 2, 3, 4};
    std::set<int> set2 = {3, 4, 5, 6};
    std::set<int> result;

    // Difference (Hiệu) có trong A nhưng không có trong B ( phần chung sẽ ko đc nhận )
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));

    // Intersection (Giao)
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));

    // Union (Hợp)
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));

    // Difference (Phần chung của cả 2 trừ phần giao)
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));

    //! =================================================================================================

    std::vector<int> sortedRange1 = {1, 3, 5, 7, 9};
    std::vector<int> sortedRange2 = {2, 4, 6, 8, 10};

    // std::merge: Merge hai sorted ranges thành một sorted range mới
    std::vector<int> mergedRange(sortedRange1.size() + sortedRange2.size());
    std::merge(sortedRange1.begin(), sortedRange1.end(), sortedRange2.begin(), sortedRange2.end(), mergedRange.begin());

    // In ra merged range
    std::cout << "Merged Range: ";
    for (int element : mergedRange) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // std::inplace_merge: Merge hai sorted ranges ngay tại chỗ (in-place)
    std::vector<int> inPlaceMergeRange = {3, 6, 8, 1, 2, 5, 7};
    std::inplace_merge(inPlaceMergeRange.begin(), inPlaceMergeRange.begin() + 3, inPlaceMergeRange.end());

    // In ra in-place merged range
    std::cout << "In-place Merged Range: ";
    for (int element : inPlaceMergeRange) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // std::includes: Kiểm tra xem một sorted range có chứa một sorted range khác không
    std::vector<int> checkIncludesRange = {1, 3, 5};
    bool includesResult = std::includes(sortedRange1.begin(), sortedRange1.end(), checkIncludesRange.begin(), checkIncludesRange.end());

    // In kết quả kiểm tra includes
    if (includesResult) {
        std::cout << "sortedRange1 includes checkIncludesRange." << std::endl;
    } else {
        std::cout << "sortedRange1 does not include checkIncludesRange." << std::endl;
    }

    return 0;
}
