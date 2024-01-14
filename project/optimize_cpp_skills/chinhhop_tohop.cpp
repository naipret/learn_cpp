#include <iostream>

//! GIAI THỪA ký hiệu là P(n) = n!
long long P(const long long n) {
    if (n < 0) {
        return -1LL;
    }
    long long s{1LL};
    for (long long i = 2LL; i <= n; ++i) {
        s *= i;
    }
    return s;
}

//! CHỈNH HỢP ký hiệu là A(k,n)
long long A(const long long k, const long long n) {
    if (k > n) {
        return -1LL;
    }
    return P(n) / P(n - k);
}

//! TỔ HỢP ký hiệu là C(k,n)
long long C(const long long k, const long long n) {
    if (k > n) {
        return -1LL;
    }
    return A(k, n) / P(k);
}

int main() {
    //! CHỈNH HỢP ký hiệu là A(k,n) (k trên n dưới): đọc là chỉnh hợp chập k của n
    // vd: A(3,6) = 6 * 5 * 4 = 120
    // vd: A(5,8) = 8 * 7 * 6 * 5 * 4 = 6720
    //! A(k,n) = n! / (n - k)! || A(k,n) = P(n) / P(n-k)
    // vd: A(5,7) = 7! / (7 - 5)! = 2520
    //! Trong máy tính Casio ký hiệu là nPr
    // vd: 7P5 = 2520
    //! Chỉnh hợp là cách xếp có phân biệt!
    // vd: xếp A và B vào 2 chỗ ngồi, ta được 2 cách xếp: A,B ; B,A
    // trái với tổ hợp không phân biệt: A,B tương tự với B,A nên chỉ có 1 cách xếp

    //! TỔ HỢP ký hiệu là C(k,n) (k trên n dưới): đọc là tổ hợp chập k của n
    // vd: C(3,6) = 20
    // vd: C(5,8) = 56
    //! C(k,n) = n! / ((n - k)! * k!) || C(k,n) = P(n) / (A(k,n) * P(k)) || C(k,n) = A(k,n) / P(k)
    // vd: C(5,7) = 7! / (7 - 5)! * 5! = 21
    //! Trong máy tính Casio ký hiệu là nCr
    // vd: 7C5 = 21
    //! Tổ hợp là cách xếp không phân biệt!
    // vd: khi chọn 3 bạn đề bầu làm ban cán sự lớp thì chọn ra 3 người trước rồi mới bỏ phiếu
    // thì khi này cả 3 người có thể làm bất kỳ chức vụ gì nên không cần phải phân biệt

    int choose{};
    int n{}, k{};
    std::cout << "1. Giai thua P(n)\n2. Chinh hop A(k,n)\n3. To hop    C(k,n)\n";
    std::cout << "Chon phep tinh can thuc hien: ";
    std::cin >> choose;
    std::cout << std::endl;
    switch (choose) {
        case 1:
            std::cout << "Nhap n = ";
            std::cin >> n;
            std::cout << "P(" << n << ") = " << P(n);
            break;
        case 2:
            std::cout << "Nhap k n = ";
            std::cin >> k >> n;
            std::cout << "A(" << k << "," << n << ") = " << A(k, n);
            break;
        case 3:
            std::cout << "Nhap k n = ";
            std::cin >> k >> n;
            std::cout << "C(" << k << "," << n << ") = " << C(k, n);
            break;
        default:
            break;
    }
    std::cout << std::endl;
    return 0;
}
