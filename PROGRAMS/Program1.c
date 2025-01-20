#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int capacity; // Maximum size of the array
    int size;     // Current number of elements

    void resize() {
        int* temp = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity *= 2;
    }

public:
    DynamicArray(int initialCapacity = 4) {
        capacity = initialCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1; // Value not found
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray da;

    // Insert elements
    da.insert(10);
    da.insert(20);
    da.insert(30);
    da.insert(40);
    da.display();

    // Remove an element
    da.remove(2); // Removes 30
    da.display();

    // Search for an element
    int index = da.search(20);
    if (index != -1) {
        cout << "20 found at index: " << index << endl;
    } else {
        cout << "20 not found!" << endl;
    }

    // Insert more elements
    da.insert(50);
    da.insert(60);
    da.display();

    return 0;
}