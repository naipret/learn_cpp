#include "..\include\triangle_type.hpp"

#include <iostream>

// forward declarations
bool equilateral_triangle(const double &a, const double &b, const double &c);
bool isosceles_right_triangle(const double &a, const double &b, const double &c);
bool isosceles_triangle(const double &a, const double &b, const double &c);
bool right_triangle(const double &a, const double &b, const double &c);
bool obtuse_triangle(const double &a, const double &b, const double &c);
bool acute_triangle(const double &a, const double &b, const double &c);

std::string triangle_type(const double &a, const double &b, const double &c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (equilateral_triangle(a, b, c)) {
            return "Tam giac deu";
        } else if (isosceles_right_triangle(a, b, c)) {
            return "Tam giac vuong can";
        } else if (isosceles_triangle(a, b, c)) {
            return "Tam giac can";
        } else if (right_triangle(a, b, c)) {
            return "Tam giac vuong";
        } else {
            return "Tam giac thuong";
        }
    } else {
        return "Khong phai la tam giac";
    }
}

std::string advance_triangle_type(const double &a, const double &b, const double &c) {
    if (a + b > c && a + c > b && b + c > a) {
        if (equilateral_triangle(a, b, c)) {
            return "Tam giac deu";
        } else if (isosceles_right_triangle(a, b, c)) {
            return "Tam giac vuong can";
        } else if (isosceles_triangle(a, b, c)) {
            return "Tam giac can";
        } else if (right_triangle(a, b, c)) {
            return "Tam giac vuong";
        } else if (obtuse_triangle(a, b, c)) {  // add obtuse triangle
            return "Tam giac tu";
        } else if (acute_triangle(a, b, c)) {  // add acute triangle
            return "Tam giac nhon";
        } else {
            return "Tam giac thuong";
        }
    } else {
        return "Khong phai la tam giac";
    }
}

// bool similar_triangle() {

// }

bool equilateral_triangle(const double &a, const double &b, const double &c) {
    if (a == b && b == c) {
        return true;
    } else {
        return false;
    }
}

bool isosceles_right_triangle(const double &a, const double &b, const double &c) {
    if (((a * a == b * b + c * c) && (b == c)) || ((b * b == a * a + c * c) && (a == c)) ||
        ((c * c == a * a + b * b) && (a == b))) {
        return true;
    } else {
        return false;
    }
}

bool isosceles_triangle(const double &a, const double &b, const double &c) {
    if (a == b || b == c || a == c) {
        return true;
    } else {
        return false;
    }
}

bool right_triangle(const double &a, const double &b, const double &c) {
    if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b)) {
        return true;
    } else {
        return false;
    }
}

bool obtuse_triangle(const double &a, const double &b, const double &c) {
    if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > a * a + b * b) {
        return true;
    } else {
        return false;
    }
}

bool acute_triangle(const double &a, const double &b, const double &c) {
    if (a * a < b * b + c * c && b * b < a * a + c * c && c * c < a * a + b * b) {
        return true;
    } else {
        return false;
    }
}
