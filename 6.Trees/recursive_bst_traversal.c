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

// Function for in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);    // Traverse left subtree
        printf("%d ", root->data);        // Visit root node
        inOrderTraversal(root->right);   // Traverse right subtree
    }
}

// Function for pre-order traversal of the BST
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);        // Visit root node
        preOrderTraversal(root->left);    // Traverse left subtree
        preOrderTraversal(root->right);   // Traverse right subtree
    }
}

// Function for post-order traversal of the BST
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);   // Traverse left subtree
        postOrderTraversal(root->right);  // Traverse right subtree
        printf("%d ", root->data);        // Visit root node
    }
}

// Function to insert a value into the BST recursively
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged node pointer
    return root;
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

    // Print traversals of the BST
    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal of the BST: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal of the BST: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}