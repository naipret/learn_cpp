#include <cmath>
#include <iostream>

using namespace std;

int main() {
    cout << "abs(-2) = " << abs(-2) << endl;  // giá trị tuyệt đối của -2
    cout << "fabs(-2.3) = " << fabs(-2.3) << endl
         << endl;  // giá trị tuyệt đối của -2.3
    //! square root
    cout << "sqrt(5) = " << sqrt(5) << endl;  // căn bậc 2 của 5
    //! cube root
    cout << "cbrt(1000) = " << cbrt(1000) << endl
         << endl;  // căn bậc 3 của 1000

    cout << "floor(2.3) = " << floor(2.3) << endl;  // làm tròn xuống, kết quả: 2
    cout << "floor(2.8) = " << floor(2.8) << endl;  // làm tròn xuống, kết quả: 2
    cout << "round(2.3) = " << round(2.3) << endl;  // làm tròn, kết quả: 2
    cout << "round(2.8) = " << round(2.8) << endl;  // làm tròn, kết quả: 3
    cout << "ceil(2.3) = " << ceil(2.3) << endl;    // làm tròn lên, kết quả: 3
    cout << "ceil(2.8) = " << ceil(2.8) << endl;  // làm tròn lên, kết quả: 3
    cout << "trunc(3.37289) = " << trunc(3.37289) << endl<< endl; // bỏ đi phần thập phân, kết quả 3

    cout << "min(5, 10) = " << min(5, 10) << endl;          // giá trị nhỏ nhất giữa 5 và 10
    cout << "max(5, 10) = " << max(5, 10) << endl;          // giá trị lớn nhất giữa 5 và 10
    cout << "fmin(2.1, 3.5) = " << fmin(2.1, 3.5) << endl;  // giá trị nhỏ nhất giữa 2.1 và 3.5
    cout << "fmax(2.1, 3.5) = " << fmax(2.1, 3.5) << endl
         << endl;  // giá trị lớn nhất giữa 2.1 và 3.5

    // cout << "mod(15, 8) = " << mod(15, 8) << endl;          // phần dư của 15 chia 8
    // cout << "15 % 8 = " << 15 % 8 << endl;                    // phần dư của 15 chia 8
    cout << "fmod(15.2, 8.7) = " << fmod(15.2, 8.7) << endl;  // phần dư của 15.2 chia 8.7
    cout << "log(2) = " << log(2) << endl;                    // logarit tự nhiên của 2
    cout << "pow(2, 3) = " << pow(2, 3) << endl
         << endl;  // 2 mũ 3
    return 0;
}
