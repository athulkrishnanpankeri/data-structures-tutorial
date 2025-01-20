#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    
    // Traverse through the array starting from the second element
    for (i = 1; i < n; i++) {
        key = arr[i];  // Store the current element to be inserted
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift the element to the right
            j = j - 1;  // Move to the next element
        }

        // Insert the key at the correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
