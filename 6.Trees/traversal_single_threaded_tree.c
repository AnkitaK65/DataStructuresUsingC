#include <stdio.h>
#include <stdlib.h>

// Structure for a threaded binary tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded; // 1 if right pointer is a thread, 0 otherwise
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = 0; // Initially, it is not threaded
    return newNode;
}

// Function to perform in-order traversal of the right-threaded binary tree
void inOrderTraversal(Node *root) {
    if (!root) return;

    Node *current = root;
    // Go to the leftmost node
    while (current && current->left != NULL) {
        current = current->left;
    }

    // Start the in-order traversal
    while (current != NULL) {
        printf("%d ", current->data);

        // If this node is threaded, move to the right
        if (current->isThreaded) {
            current = current->right;
        } else {
            // Move to the leftmost child of the right subtree
            current = current->right;
            while (current && current->left != NULL) {
                current = current->left;
            }
        }
    }
}

// Function to insert a new node into the right-threaded binary tree
void insert(Node **root, int data) {
    Node *newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node *current = *root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            if (current->isThreaded) {
                break; // Found the place to insert
            }
            current = current->right;
        }
    }

    // Insert new node
    if (data < parent->data) {
        parent->left = newNode;
        newNode->right = parent; // Thread to parent
        newNode->isThreaded = 1; // Set as threaded
    } else {
        newNode->right = parent->right;
        newNode->isThreaded = parent->isThreaded; // Copy threaded property
        parent->right = newNode;
        parent->isThreaded = 0; // Parent's right pointer is no longer a thread
    }
}

// Main function to demonstrate the threaded binary tree
int main() {
    Node *root = NULL;

    // Inserting elements into the right-threaded binary tree
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
