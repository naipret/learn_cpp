#include <algorithm>
#include <fstream>
#include <iostream>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> n;
    int arr[n] = {};
    for (int i{0}; i < n; ++i) {
        input >> arr[i];
    }
    input.close();

    std::sort(arr, arr + n);

    int *itrArr{arr};
    int *ptrVal{arr};
    int countMax{0};
    while (itrArr != (arr + n)) {
        int *ptrNextValue{std::upper_bound(itrArr, arr + n, *itrArr)};
        int tempCount{int(ptrNextValue - itrArr)};
        if (countMax < tempCount) {
            countMax = tempCount;
            ptrVal = itrArr;
        }
        itrArr = ptrNextValue;
    }

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    output << countMax << ' ' << *ptrVal;
    output.close();

    return 0;
}
