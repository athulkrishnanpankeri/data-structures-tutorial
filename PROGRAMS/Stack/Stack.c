#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Structure to represent the stack
struct Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Top of the stack
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Stack is initially empty
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    } else {
        int value = stack->arr[stack->top--];
        return value;
    }
}

// Peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;  // Declare a stack variable
    initStack(&stack);   // Initialize the stack

    push(&stack, 10);  // Push 10 to the stack
    push(&stack, 20);  // Push 20 to the stack
    push(&stack, 30);  // Push 30 to the stack
    display(&stack);   // Display stack elements

    printf("Popped: %d\n", pop(&stack));  // Pop the top element
    display(&stack);   // Display stack elements after popping

    printf("Peek: %d\n", peek(&stack));  // Peek the top element

    push(&stack, 40);  // Push 40 to the stack
    push(&stack, 50);  // Push 50 to the stack
    push(&stack, 60);  // Stack overflow (because MAX = 5)
    display(&stack);   // Display stack elements

    return 0;
}
