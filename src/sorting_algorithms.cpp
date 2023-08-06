#include "..\include\sorting_algorithms.h"

#include <iostream>

void bubbleSort(int input_arr[]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            if (input_arr[i] > input_arr[j]) {
                std::swap(input_arr[i], input_arr[j]);
            }
        }
    }
}
