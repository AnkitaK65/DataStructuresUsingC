#include <stdio.h>
#include <stdlib.h>

// Structure for a Threaded Binary Tree node
struct ThreadedNode {
    int data;
    struct ThreadedNode* left;
    struct ThreadedNode* right;
    int left_thread;  // 1 if left pointer is a thread, 0 otherwise
    int right_thread; // 1 if right pointer is a thread, 0 otherwise
};

// Function to create a new node
struct ThreadedNode* createNode(int value) {
    struct ThreadedNode* newNode = (struct ThreadedNode*)malloc(sizeof(struct ThreadedNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->left_thread = 1;  // Initially, the left pointer is a thread
    newNode->right_thread = 1; // Initially, the right pointer is a thread
    return newNode;
}

// Function to insert a value into the Threaded Binary Tree
void insert(struct ThreadedNode** root, int value) {
    struct ThreadedNode* newNode = createNode(value);

    // If the tree is empty, make the new node the root
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct ThreadedNode* current = *root;
    struct ThreadedNode* parent = NULL;

    // Traverse the tree to find the correct position for the new node
    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            if (current->left_thread == 0) {
                current = current->left;
            } else {
                break;
            }
        } else {
            if (current->right_thread == 0) {
                current = current->right;
            } else {
                break;
            }
        }
    }

    // Insert the new node as a left or right child
    if (value < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->left_thread = 0; // Left pointer is no longer a thread
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->right = newNode;
        parent->right_thread = 0; // Right pointer is no longer a thread
    }
}

// Function to perform in-order traversal of the Threaded Binary Tree
void inOrderTraversal(struct ThreadedNode* root) {
    if (root == NULL) return;

    struct ThreadedNode* current = root;

    // Go to the leftmost node
    while (current->left_thread == 0) {
        current = current->left;
    }

    // Traverse the tree
    while (current != NULL) {
        printf("%d ", current->data);

        // If there is a right thread, follow it
        if (current->right_thread == 1) {
            current = current->right;
        } else {
            // Go to the right child
            current = current->right;
            // Go to the leftmost node of the right subtree
            while (current != NULL && current->left_thread == 0) {
                current = current->left;
            }
        }
    }
}

// Main function to demonstrate insertion in a Threaded Binary Tree
int main() {
    struct ThreadedNode* root = NULL;

    // Insert values into the Threaded Binary Tree
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 18);

    // Print in-order traversal of the Threaded Binary Tree
    printf("In-order traversal of the Threaded Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
