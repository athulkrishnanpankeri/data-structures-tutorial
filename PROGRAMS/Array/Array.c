#include <stdio.h>

#define MAX_SIZE 100

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array
int insertElement(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert new element.\n");
        return size;
    }

    // Shift elements to the right
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element at the specified position
    arr[position] = element;
    return size + 1;  // New size after insertion
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index of the element
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};  // Predefined array with 5 elements
    int size = 5;  // Current size of the array
    
    // Display the array
    displayArray(arr, size);
    
    // Insert an element at a specific position
    size = insertElement(arr, size, 25, 2);  // Insert 25 at position 2
    displayArray(arr, size);
    
    // Search for an element in the array
    int element = 30;
    int index = searchElement(arr, size, element);
    if (index != -1) {
        printf("Element %d found at index %d\n", element, index);
    } else {
        printf("Element %d not found in the array.\n", element);
    }

    return 0;
}
