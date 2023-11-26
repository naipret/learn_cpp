#include "../include/triangle_type.hpp"

#include <iostream>

// forward declarations
inline bool equilateralTriangle(const double &a, const double &b, const double &c);
inline bool isoscelesRightTriangle(const double &a, const double &b, const double &c);
inline bool isoscelesTriangle(const double &a, const double &b, const double &c);
inline bool rightTriangle(const double &a, const double &b, const double &c);
inline bool obtuseTriangle(const double &a, const double &b, const double &c);
inline bool acuteTriangle(const double &a, const double &b, const double &c);

inline std::string triangleType(const double &a, const double &b, const double &c) {
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

inline std::string advancedTriangleType(const double &a, const double &b, const double &c) {
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

// inline bool similarTriangle() {

// }

inline bool equilateralTriangle(const double &a, const double &b, const double &c) {
    if (a == b && b == c) {
        return true;
    } else {
        return false;
    }
}

inline bool isoscelesRightTriangle(const double &a, const double &b, const double &c) {
    if (((a * a == b * b + c * c) && (b == c)) || ((b * b == a * a + c * c) && (a == c)) ||
        ((c * c == a * a + b * b) && (a == b))) {
        return true;
    } else {
        return false;
    }
}

inline bool isoscelesTriangle(const double &a, const double &b, const double &c) {
    if (a == b || b == c || a == c) {
        return true;
    } else {
        return false;
    }
}

inline bool rightTriangle(const double &a, const double &b, const double &c) {
    if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)) {
        return true;
    } else {
        return false;
    }
}

inline bool obtuseTriangle(const double &a, const double &b, const double &c) {
    if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b) {
        return true;
    } else {
        return false;
    }
}

inline bool acuteTriangle(const double &a, const double &b, const double &c) {
    if (a * a < b * b + c * c && b * b < a * a + c * c && c * c < a * a + b * b) {
        return true;
    } else {
        return false;
    }
}
