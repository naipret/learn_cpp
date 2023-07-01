#include "../include/custom_functions.h"
// #include <iostream>
#include <cmath>

double vector_length(double xI, double yI, double xM, double yM) {
    return sqrt(pow(xM - xI, 2) + pow(yM - yI, 2));
}