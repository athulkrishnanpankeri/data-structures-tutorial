#include <stdio.h>

// Binary search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Element found
        else if (arr[mid] > target)
            right = mid - 1; // Search left half
        else
            left = mid + 1; // Search right half
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {1, 5, 8, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, n-1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
