#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n == 0) { // base case
        return 1;
    }
    return n * factorial(n - 1); // recursive case
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0;
}
