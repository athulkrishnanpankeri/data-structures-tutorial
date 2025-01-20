#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In-order Traversal: Left, Root, Right
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);   // Visit left subtree
        printf("%d ", root->data);      // Visit root
        inorderTraversal(root->right);  // Visit right subtree
    }
}

// Pre-order Traversal: Root, Left, Right
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);      // Visit root
        preorderTraversal(root->left);  // Visit left subtree
        preorderTraversal(root->right); // Visit right subtree
    }
}

// Post-order Traversal: Left, Right, Root
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // Visit left subtree
        postorderTraversal(root->right); // Visit right subtree
        printf("%d ", root->data);       // Visit root
    }
}

// Main function to demonstrate tree traversal
int main() {
    // Creating a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Printing the tree traversals
    printf("In-order Traversal: ");
    inorderTraversal(root);  // Expected output: 4 2 5 1 6 3 7
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root); // Expected output: 1 2 4 5 3 6 7
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root); // Expected output: 4 5 2 6 7 3 1
    printf("\n");

    return 0;
}

