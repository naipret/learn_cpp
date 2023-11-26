#include <cmath>
#include <iostream>

using namespace std;

int main() {
    cout << "abs(-2) = " << abs(-2) << endl;
    cout << "fabs(-2.3) = " << fabs(-2.3) << endl
         << endl;
    cout << "sqrt(5) = " << sqrt(5) << endl;
    cout << "cbrt(1000) = " << cbrt(1000) << endl
         << endl;
    cout << "floor(2.3) = " << floor(2.3) << endl;  // = 2 // dưới
    cout << "floor(2.8) = " << floor(2.8) << endl;  // = 2
    cout << "round(2.3) = " << round(2.3) << endl;  // = 2 // trung
    cout << "round(2.8) = " << round(2.8) << endl;  // = 3
    cout << "ceil(2.3) = " << ceil(2.3) << endl;    // = 3 // trên
    cout << "ceil(2.8) = " << ceil(2.8) << endl     // = 3
         << endl;
    cout << "min(5, 10) = " << min(5, 10) << endl;
    cout << "max(5, 10) = " << max(5, 10) << endl;
    cout << "fmin(2.1, 3.5) = " << fmin(2.1, 3.5) << endl;
    cout << "fmax(2.1, 3.5) = " << fmax(2.1, 3.5) << endl
         << endl;
    cout << "fmod(15, 8) = " << fmod(15, 8) << endl;
    cout << "log(2) = " << log(2) << endl;
    cout << "pow(2, 3) = " << pow(2, 3) << endl
         << endl;
    cout << "rint(43.6) = " << rint(43.6) << endl;
    cout << "rint(43.3) = " << rint(43.3) << endl;
    system("pause");
}
