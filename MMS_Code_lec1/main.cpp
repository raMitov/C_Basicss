#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

//ex1
double abs(double x) {
    return x > 0 ? x : -x;
}
double squreRoot(double n) {
    n = abs(n);
    if (n < 2) return n;
    double y = n;
    double z = (y +(n/y)) / 2;
    while (abs(y - z) >= 0.00001) {
        y = z;
        z = (y +(n/y)) / 2;
    }
    return z;
}
//ex2
void map(const double* input, int size, double(*F)(double), double* output) {
    for (int i = 0; i < size; i++) {
        output[i] = F(input[i]);
    }
}
//Functions for EX2
double square(double x) {
    return x * x;
}
double absolute(double x) {
    //using my own abs :D :D :D
    return abs(x);
}
//ex3
void insertAfter(double *arr, int size, int index, double newElement) {
    if (0 <= index && index < size - 1) {
        for (int i = size - 1; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index+1] = newElement;
    }
}
void deletee(double *arr, int size, int index){
    if (0 <= index && index < size ) {
        int i = 0;
        for (i = index; i < size - 1 && arr[i] != 0; i++) {
            arr[i] = arr[i + 1];
        }
        arr[i] = 0;
    }

}
void revers(double *arr, int size) {
    double temp[size];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[size - 1 - i];
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}
void sort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}
void sort(int* array, int size, bool (*comparator)(int, int)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (!comparator(array[i], array[j])) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

// Example comparator functions
bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}
int find(int* array, int size, bool (*predicate)(int)) {
    for (int i = 0; i < size; ++i) {
        if (predicate(array[i])) {
            return i;
        }
    }
    return -1;
}
bool isEven(int x) {
    return x % 2 == 0;
}
int main() {

    //ex1 Test
    double n;
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "The SQRT of N is: "<<squreRoot(n) << std::endl;
    //ex2 Test
    const int size = 5;
    double input[size] = {-4.5, -3.2, 2.0, 5.5, -1.};
    double output[size];
    map(input, size, absolute, output);
    std::cout << "The absolute of N is: " << output[0] << std::endl;
    map(input, size, square, output);
    std::cout << "The square of N is: " << output[0] << std::endl;
    return 0;
}
