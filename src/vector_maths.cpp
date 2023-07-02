#include "..\include\vector_maths.h"

#include <cmath>  // to use sqrt(),
#include <iostream>

double onePointVectorLength(double xM, double yM) {
    return sqrt(pow(xM, 2) + pow(yM, 2));
}

double twoPointVectorLength(double xM, double yM, double xN, double yN) {
    return sqrt(pow(xN - xM, 2) + pow(yN - yM, 2));
}
