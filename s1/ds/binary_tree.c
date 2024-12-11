#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given value
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new value into the binary search tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to perform an in-order traversal of the binary search tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);  // Visit left subtree
        printf("%d ", root->data);  // Print the root node's data
        inorder(root->right);  // Visit right subtree
    }
}

// Main function to demonstrate the BST operations
int main() {
    struct Node* root = NULL;
    int n, value;

    // Ask the user how many elements they want to insert
    printf("Enter the number of elements to insert into the binary search tree: ");
    scanf("%d", &n);

    // Take user input for the elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);  // Insert each element into the tree
    }

    // Perform an in-order traversal (should print the nodes in sorted order)
    printf("In-order traversal of the binary search tree: ");
    inorder(root);
    printf("\n");

    return 0;
}



