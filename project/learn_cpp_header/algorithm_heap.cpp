#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // make_heap
    std::make_heap(numbers.begin(), numbers.end());
    std::cout << "Heap after make_heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // push_heap
    numbers.push_back(7);
    std::push_heap(numbers.begin(), numbers.end());
    std::cout << "Heap after push_heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // pop_heap
    std::pop_heap(numbers.begin(), numbers.end());
    std::cout << "Heap after pop_heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // sort_heap
    std::sort_heap(numbers.begin(), numbers.end());
    std::cout << "Heap after sort_heap: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // is_heap
    bool isHeap = std::is_heap(numbers.begin(), numbers.end());
    std::cout << "Is the range a heap? " << (isHeap ? "Yes" : "No") << std::endl;

    // is_heap_until
    auto notInHeap = std::is_heap_until(numbers.begin(), numbers.end());
    std::cout << "First element not in heap order is at index: " << std::distance(numbers.begin(), notInHeap) << std::endl;

    return 0;
}
