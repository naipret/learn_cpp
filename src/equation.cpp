#include <cmath>
#include <iostream>

double firstDegreeEquation(const double &a, const double &b = 0, bool output = 0) {
    double x{(-b) / a};
    return x;
}

void quadraticEquation(const double &a, const double &b, const double &c = 0, bool output = 0) {
    double delta{(b * b) - (4 * a * c)};
    double x{};
    if (delta == 0) {

    }
}