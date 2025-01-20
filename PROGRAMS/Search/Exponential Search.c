#include <stdio.h>

// Binary search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Exponential search function
int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target) return 0; // Element at the first position
    
    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2; // Double the index
    }
    
    // Binary search in the range [i/2, min(i, n-1)]
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
}

int main() {
    int arr[] = {1, 5, 8, 10, 15, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = exponentialSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
