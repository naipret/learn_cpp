#include <algorithm>
#include <iostream>

int main() {
    long long arr[5]{};
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    std::sort(arr, std::end(arr));

    std::cout << arr[1];

    return 0;
}
