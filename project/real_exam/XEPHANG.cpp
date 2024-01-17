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

    int *itr{std::adjacent_find(arr, arr + n)};
    int *ptr_viTri{arr};
    int khoangCachMax{0};
    while (itr != (arr + n)) {
        int *ptr_viTriSoTiepTheo{std::upper_bound(itr, arr + n, *itr)};
        if (khoangCachMax < (ptr_viTriSoTiepTheo - itr)) {
            ptr_viTri = itr;
            khoangCachMax = ptr_viTriSoTiepTheo - itr;
        }
        itr = std::adjacent_find(ptr_viTriSoTiepTheo++, arr + n);
    }

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    output << khoangCachMax << ' ' << *ptr_viTri;
    output.close();

    return 0;
}
