#include "..\include\vector_maths.h"

#include <cmath>  // to use sqrt(),
#include <iostream>

double onePointVectorLength(const double &xM, const double &yM) {
    return sqrt(pow(xM, 2) + pow(yM, 2));
}

double twoPointVectorLength(const double &xM, const double &yM, const double &xN = 0, const double &yN = 0) {
    return sqrt(pow(xN - xM, 2) + pow(yN - yM, 2));
}
