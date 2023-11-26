#include "../include/triangle_type.hpp"

#include <iostream>

// forward declarations
bool equilateralTriangle(const double &a, const double &b, const double &c);
bool isoscelesRightTriangle(const double &a, const double &b, const double &c);
bool isoscelesTriangle(const double &a, const double &b, const double &c);
bool rightTriangle(const double &a, const double &b, const double &c);
bool obtuseTriangle(const double &a, const double &b, const double &c);
bool acuteTriangle(const double &a, const double &b, const double &c);

std::string triangleType(const double &a, const double &b, const double &c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (equilateralTriangle(a, b, c)) {
            return "Tam giac deu";
        } else if (isoscelesRightTriangle(a, b, c)) {
            return "Tam giac vuong can";
        } else if (isoscelesTriangle(a, b, c)) {
            return "Tam giac can";
        } else if (rightTriangle(a, b, c)) {
            return "Tam giac vuong";
        } else {
            return "Tam giac thuong";
        }
    } else {
        return "Khong phai la tam giac";
    }
}

std::string advancedTriangleType(const double &a, const double &b, const double &c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (equilateralTriangle(a, b, c)) {
            return "Tam giac deu";
        } else if (isoscelesRightTriangle(a, b, c)) {
            return "Tam giac vuong can";
        } else if (isoscelesTriangle(a, b, c)) {
            return "Tam giac can";
        } else if (rightTriangle(a, b, c)) {
            return "Tam giac vuong";
        } else if (obtuseTriangle(a, b, c)) {  // add obtuse triangle
            return "Tam giac tu";
        } else if (acuteTriangle(a, b, c)) {  // add acute triangle
            return "Tam giac nhon";
        } else {
            return "Tam giac thuong";
        }
    } else {
        return "Khong phai la tam giac";
    }
}

// bool similarTriangle() {

// }

bool equilateralTriangle(const double &a, const double &b, const double &c) {
    if (a == b && b == c) {
        return true;
    } else {
        return false;
    }
}

bool isoscelesRightTriangle(const double &a, const double &b, const double &c) {
    if (((a * a == b * b + c * c) && (b == c)) || ((b * b == a * a + c * c) && (a == c)) ||
        ((c * c == a * a + b * b) && (a == b))) {
        return true;
    } else {
        return false;
    }
}

bool isoscelesTriangle(const double &a, const double &b, const double &c) {
    if (a == b || b == c || a == c) {
        return true;
    } else {
        return false;
    }
}

bool rightTriangle(const double &a, const double &b, const double &c) {
    if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)) {
        return true;
    } else {
        return false;
    }
}

bool obtuseTriangle(const double &a, const double &b, const double &c) {
    if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b) {
        return true;
    } else {
        return false;
    }
}

bool acuteTriangle(const double &a, const double &b, const double &c) {
    if (a * a < b * b + c * c && b * b < a * a + c * c && c * c < a * a + b * b) {
        return true;
    } else {
        return false;
    }
}
