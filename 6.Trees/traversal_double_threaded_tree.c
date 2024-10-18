#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a double threaded binary tree
typedef struct Node {
    int data;
    struct Node *left, *right;
    int lThread, rThread;  // lThread is 1 if left pointer is a thread, rThread is 1 if right pointer is a thread
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->lThread = temp->rThread = 1;  // Initially, left and right are threads (as NULL)
    return temp;
}

// Utility function to find the leftmost node in a tree/subtree
Node* leftmost(Node* node) {
    while (node != NULL && node->lThread == 0)
        node = node->left;
    return node;
}

// In-order traversal of a double threaded binary tree
void inorder(Node* root) {
    Node* current = leftmost(root);  // Start with the leftmost node

    while (current != NULL) {
        printf("%d ", current->data);

        // If the current node is threaded, follow the thread
        if (current->rThread == 1)
            current = current->right;
        else
            // Else, move to the leftmost node in the right subtree
            current = leftmost(current->right);
    }
}

// Pre-order traversal of a double threaded binary tree
void preorder(Node* root) {
    Node* current = root;

    while (current != NULL) {
        printf("%d ", current->data);

        // If left pointer is not a thread, move to left child
        if (current->lThread == 0)
            current = current->left;
        else {
            // Else, move to the right child or successor (thread)
            while (current != NULL && current->rThread == 1)
                current = current->right;

            // If right child is not a thread, move there
            if (current != NULL)
                current = current->right;
        }
    }
}

// Function to insert a node in a double threaded binary tree
Node* insert(Node* root, int key) {
    // Start with the root and search for the correct position
    Node* parent = NULL;
    Node* current = root;

    while (current != NULL) {
        // If the key already exists, return root
        if (key == current->data) {
            return root;
        }

        parent = current;

        if (key < current->data) {
            if (current->lThread == 0)
                current = current->left;
            else
                break;
        } else {
            if (current->rThread == 0)
                current = current->right;
            else
                break;
        }
    }

    // Create a new node
    Node* newNodePtr = newNode(key);

    if (parent == NULL) {
        // If tree is empty, the new node becomes the root
        root = newNodePtr;
    } else if (key < parent->data) {
        // Insert as left child
        newNodePtr->left = parent->left;
        newNodePtr->right = parent;
        parent->lThread = 0;
        parent->left = newNodePtr;
    } else {
        // Insert as right child
        newNodePtr->right = parent->right;
        newNodePtr->left = parent;
        parent->rThread = 0;
        parent->right = newNodePtr;
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Inserting nodes into the double threaded binary tree
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    printf("In-order traversal of the double threaded binary tree:\n");
    inorder(root);

    printf("\nPre-order traversal of the double threaded binary tree:\n");
    preorder(root);

    return 0;
}
