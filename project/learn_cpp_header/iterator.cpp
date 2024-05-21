#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
    std::set<int> vec = {1, 2, 3, 4, 5};
    std::set<int> destination;

    // Sử dụng std::inserter để chèn các phần tử từ source vào destination
    std::copy(vec.begin(), vec.end(), std::inserter(destination, destination.begin()));

    // In ra các phần tử của destination
    for (int element : destination) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (auto it = std::begin(vec); it != std::end(vec); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Ví dụ sử dụng advance:
    auto it = std::begin(vec);
    std::advance(it, 2);
    std::cout << "Element after advancing: " << *it << std::endl;

    // Ví dụ sử dụng distance:
    auto first = std::begin(vec);
    auto last = std::end(vec);
    int dist = std::distance(first, last);
    std::cout << "Distance between first and last: " << dist << std::endl;

    //! int n{vec.size()};

    // Ví dụ sử dụng next và prev:
    auto next_it = std::next(std::begin(vec));
    auto prev_it = std::prev(next_it);
    std::cout << "Next element: " << *next_it << std::endl;
    std::cout << "Previous element: " << *prev_it << std::endl;

    return 0;
}
