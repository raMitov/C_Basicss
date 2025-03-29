#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/fs_path.h>
//EX1
//sorts grades from smallest to biggest
//The algorhytm is counting sort
//Im using a copy of the array but I think this should be the fastest time complexity for sure
void SortGrades (int inputArr[], int size) {
    const int MAX_VAL = 100;
    int count[MAX_VAL + 1] = {0};
    int output[size];
    for (int i = 0; i < size; i++) {
        count[inputArr[i]]++;
    }
    for (int i = 1; i <= MAX_VAL; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[inputArr[i]] - 1] = inputArr[i];
        count[inputArr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        inputArr[i] = output[i];
    }
}
//EX2
//helper functions below
// int firstDigit(int n) {
//     while (n >= 10) n/=10;
//
//     return n;
// }
// int secondDigit(int n) {
//     while (n >= 100) n/=100;
//     return n;
// }
// //function for the task
//
// int biggestNumberFromArray(int arr[], const int size) {
//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (firstDigit(arr[i]) <= firstDigit(arr[j])) {
//                 if (firstDigit(arr[i]) == firstDigit(arr[j])) {
//                     if (arr[i] < arr[j]) {
//                         std::swap(arr[i], arr[j]);
//                     }
//                 }
//                 else {
//                     std::swap(arr[i], arr[j]);
//                 }
//             }
//
//         }
//     }
//     std::ostringstream oss;
//     for (int i = 0; i < size; i++) {
//         oss << arr[i];
//     }
//     std::string str = oss.str();
//     int res = stoi(str);
//     return res;
// }
//This above doesnt work but it still has some value maybe :D

//This below works :D
//Helper Func
bool compare(int a, int b) {
    std::string str1 = std::to_string(a) + std::to_string(b);
    std::string str2 = std::to_string(b) + std::to_string(a);
    return str1 > str2;
}
//Func
int biggestNumberFromArray(int arr[], int size) {
    std::vector<int> nums(arr, arr + size);
    sort(nums.begin(), nums.end(), compare);
    std::ostringstream oss;
    for (int num : nums) {
        oss << num;
    }
    int res = stoi(oss.str());
    return res;
}
//EX4
//heapify
void heapify(std::vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//EX3
void merge(int arr[], int low, int high, int mid) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[j];
            k++;
            i++;
        }
        else {
            c[k] = arr[i];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
    return;
}

int main() {
    int size = 5;
    int arr[5] = {3, 30, 34, 5, 9};
    SortGrades(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    int test2 = biggestNumberFromArray(arr, size);
    std::cout << test2 << std::endl;
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.