#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST iteratively
struct Node* insert(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    
    // If the tree is empty, return the new node
    if (root == NULL) {
        return newNode;
    }

    struct Node* current = root;
    struct Node* parent = NULL;

    // Traverse the tree to find the correct position
    while (current != NULL) {
        parent = current;  // Keep track of the parent
        if (value < current->data) {
            current = current->left;  // Move to left child
        } else if (value > current->data) {
            current = current->right;  // Move to right child
        } else {
            // Value already exists in the BST
            free(newNode); // Free allocated memory
            return root;   // Return the unchanged root
        }
    }

    // Insert the new node in the correct position
    if (value < parent->data) {
        parent->left = newNode; // Insert as left child
    } else {
        parent->right = newNode; // Insert as right child
    }

    return root; // Return the unchanged root
}

// Function for in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print in-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
