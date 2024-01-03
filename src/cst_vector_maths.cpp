#include <cmath>  // to use std::sqrt(), std::pow()

#include "cst_vector_maths.hpp"

namespace cst {
    double vectorLength(const double &xM, const double &yM, const double &xN = 0.0,
                        const double &yN = 0.0) {
        return std::sqrt(std::pow(xN - xM, 2) + std::pow(yN - yM, 2));
    }
    long double vectorLength(const long double &xM, const long double &yM,
                            const long double &xN = 0.0L, const long double &yN = 0.0L) {
        return std::sqrt(std::pow(xN - xM, 2) + std::pow(yN - yM, 2));
    }
}  // namespace cst
