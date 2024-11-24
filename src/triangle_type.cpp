#include "triangle_type.hpp"

#include <string>

namespace cst {
    // forward declarations
    bool isEquilateralTriangle(const double &a, const double &b, const double &c);
    bool isIsoscelesRightTriangle(const double &a, const double &b, const double &c);
    bool isIsoscelesTriangle(const double &a, const double &b, const double &c);
    bool isRightTriangle(const double &a, const double &b, const double &c);
    bool isObtuseTriangle(const double &a, const double &b, const double &c);
    bool isAcuteTriangle(const double &a, const double &b, const double &c);
    // forward declarations
    std::string triangleType(const double &a, const double &b, const double &c) {
        if (a + b > c && a + c > b && b + c > a) {
            if (isEquilateralTriangle(a, b, c)) {
                return "Tam giac deu";
            } else if (isIsoscelesRightTriangle(a, b, c)) {
                return "Tam giac vuong can";
            } else if (isIsoscelesTriangle(a, b, c)) {
                return "Tam giac can";
            } else if (isRightTriangle(a, b, c)) {
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
            if (isEquilateralTriangle(a, b, c)) {
                return "Tam giac deu";
            } else if (isIsoscelesRightTriangle(a, b, c)) {
                return "Tam giac vuong can";
            } else if (isIsoscelesTriangle(a, b, c)) {
                return "Tam giac can";
            } else if (isRightTriangle(a, b, c)) {
                return "Tam giac vuong";
            } else if (isObtuseTriangle(a, b, c)) {  // add obtuse triangle
                return "Tam giac tu";
            } else if (isAcuteTriangle(a, b, c)) {  // add acute triangle
                return "Tam giac nhon";
            } else {
                return "Tam giac thuong";
            }
        } else {
            return "Khong phai la tam giac";
        }
    }
    bool isEquilateralTriangle(const double &a, const double &b, const double &c) {
        if (a == b && b == c) {
            return true;
        } else {
            return false;
        }
    }
    bool isIsoscelesRightTriangle(const double &a, const double &b, const double &c) {
        if (((a * a == b * b + c * c) && (b == c)) || ((b * b == a * a + c * c) && (a == c)) ||
            ((c * c == a * a + b * b) && (a == b))) {
            return true;
        } else {
            return false;
        }
    }
    bool isIsoscelesTriangle(const double &a, const double &b, const double &c) {
        if (a == b || b == c || a == c) {
            return true;
        } else {
            return false;
        }
    }
    bool isRightTriangle(const double &a, const double &b, const double &c) {
        if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)) {
            return true;
        } else {
            return false;
        }
    }
    bool isObtuseTriangle(const double &a, const double &b, const double &c) {
        if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b) {
            return true;
        } else {
            return false;
        }
    }
    bool isAcuteTriangle(const double &a, const double &b, const double &c) {
        if (a * a < b * b + c * c && b * b < a * a + c * c && c * c < a * a + b * b) {
            return true;
        } else {
            return false;
        }
    }
}  // namespace cst
