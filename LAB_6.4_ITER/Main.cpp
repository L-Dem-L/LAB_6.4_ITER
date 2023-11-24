#include <iostream>
#include <iomanip>
#include <cmath>

void fillArray(double* arr, int size) {
    std::cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printArray(const double* arr, int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(8) << std::fixed << std::setprecision(2) << arr[i] << " ";
    }
    std::cout << std::endl;
}

int countZeros(const double* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }
    return count;
}

double sumAfterMin(const double* arr, int size) {
    if (size == 0) {
        return 0.0;
    }

    double minElement = arr[0];
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }

    double sum = 0.0;
    for (int i = minIndex + 1; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

void sortOddElements(double* arr, int size) {
    for (int i = 0; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (std::abs(arr[i]) > std::abs(arr[j])) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int size;

    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Invalid array size\n";
        return 1;
    }

    double* arr = new double[size];

    fillArray(arr, size);
    printArray(arr, size);

    std::cout << "1.1. Number of elements equal to zero: " << countZeros(arr, size) << std::endl;

    double sumAfterMinResult = sumAfterMin(arr, size);
    std::cout << "1.2. Sum of elements after the minimum element: " << std::fixed << std::setprecision(2)
        << sumAfterMinResult << std::endl;

    sortOddElements(arr, size);

    std::cout << "Modified Array: ";
    printArray(arr, size);

    delete[] arr;

    return 0;
}

