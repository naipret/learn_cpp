#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>

int main() {
    std::set<int> source = {1, 2, 3, 4, 5};
    std::set<int> destination;

    // Sử dụng std::inserter để chèn các phần tử từ source vào destination
    std::copy(source.begin(), source.end(), std::inserter(destination, destination.begin()));

    // In ra các phần tử của destination
    for (int element : destination) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
