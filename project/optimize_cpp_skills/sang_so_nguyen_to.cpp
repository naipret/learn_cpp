#include <cmath>
#include <cstring>  // std::memset
#include <iostream>
#include <algorithm>

constexpr int maxElement{10000000};
// thuật toán này chỉ sàng được tối đa 10^7 phần tử
bool prime[maxElement + 1];
// mảng luôn + 1 để đảm bảo luôn đủ

void sieve() {
    // bước 1: xem như toàn bộ phần tử trong mảng đều là số nguyên tố
    std::memset(prime, true, sizeof(prime));
    // std::fill(prime, prime + maxElement + 1, true);
    // bước 2: loại thủ công 2 số 0 và 1 không phải là số nguyên tố
    prime[0] = prime[1] = false;
    // bước 3: kiểm tra các bội của các số, nếu là bội thì không phải là số nguyên tố
    // lưu ý: số nguyên tố thì chỉ kiểm tra đến sqrt(n) thôi
    for (int i{2}; i <= int(std::sqrt(maxElement)); ++i) {
        if (prime[i]) {
            // các bội của j thì lấy j += i
            for (int j{i * i}; j <= maxElement; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    constexpr int test[10] = {12, 56, 324425, 8764, 42423, 6534377, 8543, 859430, 4789320, 10000000 - 9};

    std::cout << "Kiem tra so nguyen to:\n";
    for (int i : test) {
        if (prime[i]) {
            std::cout << i << " la so nguyen to!\n";
        } else {
            std::cout << i << "\n";
        }
    }

    // for (int i{9991999}; i < 10000000 - 5; ++i) {
    //     if (prime[i]) {
    //         std::cout << i << " la so nguyen to!\n";
    //     } else {
    //         std::cout << i << "\n";
    //     }
    // }
    std::cout << std::endl;

    return 0;
}
