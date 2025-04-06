#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int *arr = NULL;     // pointer to the array
    int size = 0;        // number of elements currently stored
    int capacity = 2;    // initial capacity

    arr = (int*) malloc(capacity * sizeof(int));  // Allocate space for integers
    FILE *fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int num;
    bool isValid = true; // To track if the file is valid or not

    while (1) {
        char ch = fgetc(fptr);

        // End of file reached
        if (ch == EOF) {
            break;
        }

        // If the character is a valid digit or a minus sign (for negative numbers)
        if (isdigit(ch) || ch == '-' || ch == '+') {
            ungetc(ch, fptr);  // Put the character back to start reading the full number

            // Read a full integer using fscanf (it will handle multi-digit numbers)
            if (fscanf(fptr, "%d", &num) != 1) {
                isValid = false;
                break;  // Invalid number encountered, stop further processing
            }

            // Store the valid integer in the array
            if (size == capacity) {
                capacity *= 2;
                int *temp = (int*) realloc(arr, capacity * sizeof(int));
                if (temp == NULL) {
                    free(arr);
                    fprintf(stderr, "Memory reallocation failed!\n");
                    exit(1);
                }
                arr = temp;
            }
            arr[size++] = num;
        }
        // If it's a letter, punctuation, or floating-point number, mark the file as invalid
        else if (isalpha(ch) || ispunct(ch) || ch == '.') {
            isValid = false;
            break;
        }
    }

    // If invalid data was encountered, print an error message
    if (!isValid) {
        printf("The file is not valid :D\n");
        free(arr);
        fclose(fptr);
        return 0;
    }

    // Check if the numbers are in strictly increasing order
    for (int i = 1; i < size; i++) {
        if (arr[i] <= arr[i - 1]) {
            printf("The file is not valid :D\n");
            free(arr);
            fclose(fptr);
            return 0;
        }
    }

    // If all checks passed, print the success message
    printf("The file is valid and sorted in increasing order :D\n");

    free(arr);  // Free the dynamically allocated memory
    fclose(fptr);  // Close the file
    return 0;
}
