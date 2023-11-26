#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

// Bubble sort implementation
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quicksort implementation
template <typename T>
void quicksort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivot = std::partition(arr.begin() + low, arr.begin() + high, [&arr, high](const auto& element) {
            return element < arr[high];
        }) - arr.begin();
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}


// Mergesort implementation
template <typename T>
void merge(std::vector<T>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> leftArray(n1);
    std::vector<T> rightArray(n2);

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArray[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Function to generate a vector with random integers
std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec;
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < size; ++i) {
        vec.push_back(rand());
    }
    return vec;
}

int main() {
    const int size = 10000;  // Adjust the size of the data set

    // Generate a random vector
    std::vector<int> data = generateRandomVector(size);

    // Measure time for std::sort
    auto startTime = std::chrono::high_resolution_clock::now();
    std::sort(data.begin(), data.end());
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "std::sort: " << duration << " microseconds\n";

    // Generate a new random vector
    data = generateRandomVector(size);

    // Measure time for bubble sort
    startTime = std::chrono::high_resolution_clock::now();
    bubbleSort(data);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Bubble sort: " << duration << " microseconds\n";

    // Generate a new random vector
    data = generateRandomVector(size);

    // Measure time for quicksort
    startTime = std::chrono::high_resolution_clock::now();
    quicksort(data, 0, size - 1);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Quicksort: " << duration << " microseconds\n";

    // Generate a new random vector
    data = generateRandomVector(size);

    // Measure time for mergesort
    startTime = std::chrono::high_resolution_clock::now();
    mergeSort(data, 0, size - 1);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "Mergesort: " << duration << " microseconds\n";

    return 0;
}
