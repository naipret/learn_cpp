#include <algorithm>
#include <ctime>
#include <iostream>

int main() {
    constexpr unsigned int index{65535};
    unsigned int array[index]{};

    for (unsigned int i = 0; i < index; ++i) {
        array[i] = std::rand() % 4294967295;
    }

    clock_t start{clock()};

    //! sort
    std::sort(array, array + index);
    //! comment it to disable

    unsigned long long sum{};

    for (unsigned int i = 0; i < index * 2U; ++i) {
        for (unsigned int j = 0; j < index; ++j) {
            if (array[j] <= 2147483647U) {
                sum += static_cast<unsigned long long>(array[j]);
            }
        }
    }

    double elapsedTime{static_cast<double>(clock() - start) / CLOCKS_PER_SEC};

    std::cout << elapsedTime << "\n";
    std::cout << sum << std::endl;

    return 0;
}
