#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 3, 7, 4, 6};
    std::vector<int> originalNumbers = numbers;

    //! ===========================================================================
    //* Thuật toán xap xep này duoc sử dụng để xap xep một day số hoặc các phan tu của một container.
    //* Nó la một thuật toán khong ổn định, nghĩa la nếu có hai phan tu có giá trị bằng nhau, thì khong đảm bảo rằng thu tự tương đối của chúng sẽ duoc giữ nguyên sau khi xap xep.
    //* Có hiệu suất tốt hơn so với std::stable_sort, nhưng khong đảm bảo tính ổn định.
    //* std::sort thường sử dụng thuật toán Quicksort hoặc Introsort, la các thuật toán xap xep khong ổn định nhưng có độ phức tạp thời gian trung bình nhanh hơn.
    //! xap xep mang bằng hàm sort
    std::sort(numbers.begin(), numbers.end());
    std::cout << "mang sau khi xap xep (sort): ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //* Tương tự như std::sort, nhưng la một thuật toán ổn định. Nghĩa la nếu có hai phan tu bằng nhau, thì thu tự tương đối của chúng sẽ duoc giữ nguyên sau khi xap xep.
    //* Hiệu suất thường kém hơn so với std::sort, đặc biệt la khi xap xep các day số lớn.
    //* std::stable_sort thường sử dụng thuật toán Mergesort, la một thuật toán xap xep ổn định nhưng có độ phức tạp thời gian trung bình chậm hơn một chút.
    //! xap xep mang bằng hàm stable_sort
    std::vector<int> numbersStable = {5, 2, 8, 1, 3, 7, 4, 6};
    std::stable_sort(numbersStable.begin(), numbersStable.end());
    std::cout << "mang sau khi xap xep (stable_sort): ";
    for (int num : numbersStable) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    //! ===========================================================================

    std::cout << std::endl;

    //! ===========================================================================
    //! Kiểm tra xem mang có duoc xap xep khong bằng hàm is_sorted
    std::vector<int> sortedNumbers = {1, 2, 3, 4, 5};
    if (std::is_sorted(sortedNumbers.begin(), sortedNumbers.end())) {
        std::cout << "mang da duoc xap xep. (is_sorted)" << std::endl;
    } else {
        std::cout << "mang chưa duoc xap xep. (is_sorted)" << std::endl;
    }

    //! Tìm vị trí của phan tu dau tien khong duoc xap xep bằng hàm is_sorted_until
    std::vector<int> unsortedNumbers = {1, 2, 3, 5, 4};
    auto it = std::is_sorted_until(unsortedNumbers.begin(), unsortedNumbers.end());
    if (it == unsortedNumbers.end()) {
        std::cout << "mang da duoc xap xep den cuoi. (is_sorted_until)" << std::endl;
    } else {
        std::cout << "phan tu dau tien khong duoc xap xep la: (is_sorted_until) " << *it << std::endl;
    }
    //! ===========================================================================

    std::cout << std::endl;
    
    //! ===========================================================================
    //! xap xep mang bằng hàm partial_sort
    std::vector<int> numbersPartialSort = {5, 2, 8, 1, 3, 7, 4, 6};
    std::partial_sort(numbersPartialSort.begin(), numbersPartialSort.begin() + 3, numbersPartialSort.end());
    std::cout << "Ba phan tu nho nhat sau khi xap xep (partial_sort): ";
    for (int num : numbersPartialSort) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    //! xap xep mang và sao chep kết quả vào mang khác bằng hàm partial_sort_copy
    std::vector<int> source = {5, 2, 8, 1, 3, 7, 4, 6};
    std::vector<int> destination(3);
    std::partial_sort_copy(source.begin(), source.end(), destination.begin(), destination.end());
    std::cout << "Ba phan tu nho nhat sau khi xap xep va sao chep (partial_sort_copy): ";
    for (int num : destination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    //! ===========================================================================

    std::cout << std::endl;

    //! ===========================================================================
    //! xap xep phan tu thu 4 trong mang bằng hàm nth_element
    std::vector<int> nthElementNumbers = {5, 2, 8, 1, 3, 7, 4, 6};
    std::nth_element(nthElementNumbers.begin(), nthElementNumbers.begin() + 3, nthElementNumbers.end());
    std::cout << "phan tu thu 4 sau khi xap xep (nth_element): " << nthElementNumbers[3] << std::endl;
    //! ===========================================================================

    std::cout << std::endl;

    //! ===========================================================================
    numbers = originalNumbers;
    std::inplace_merge(numbers.begin(), numbers.begin() + 4, numbers.end());
    std::cout << "Day sau khi xap xep va tron: (inplace_merge) ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    //! ===========================================================================

    std::cout << std::endl;
    
    //! ===========================================================================
    numbers = originalNumbers;
    std::make_heap(numbers.begin(), numbers.end());
    std::sort_heap(numbers.begin(), numbers.end());
    std::cout << "day sau khi xap xep heap: (make_heap, sort_heap) ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    //! ===========================================================================

    std::cout << std::endl;

    return 0;
}
