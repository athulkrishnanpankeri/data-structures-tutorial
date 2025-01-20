#include <stdio.h>

// Function to merge two halves
void merge(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Recursively sort the two halves
        merge(arr, left, mid);        // Left half
        merge(arr, mid + 1, right);   // Right half
        
        // Merge the two halves
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        // Merge the temp arrays back into the original array
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of leftArr[], if any
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        // Copy remaining elements of rightArr[], if any
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
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
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    merge(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
