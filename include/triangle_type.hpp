#ifndef CST_TRIANGLE_TYPE_HPP
#define CST_TRIANGLE_TYPE_HPP

#include <string>

namespace cst {
    bool isEquilateralTriangle(const double &a, const double &b, const double &c);
    bool isIsoscelesRightTriangle(const double &a, const double &b, const double &c);
    bool isIsoscelesTriangle(const double &a, const double &b, const double &c);
    bool isRightTriangle(const double &a, const double &b, const double &c);
    bool isObtuseTriangle(const double &a, const double &b, const double &c);
    bool isAcuteTriangle(const double &a, const double &b, const double &c);
    std::string triangleType(const double &a, const double &b, const double &c);
    std::string advancedTriangleType(const double &a, const double &b, const double &c);
}  // namespace cst

#endif /* CST_TRIANGLE_TYPE_HPP */
