#include <stdio.h>
#include <stdlib.h>

//        20
//       /  \
//      10   30
//     /  \
//    5   15

// Definition of the node structure
struct Node {
    int data;
    struct Node *left, *right;
    int rightThread;  // 1 if right pointer is a thread, otherwise 0
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    newNode->rightThread = 1;  // Initially, the right pointer will be a thread
    return newNode;
}

// Function to insert a node in a single-threaded binary tree
struct Node* insert(struct Node* root, int key) {
    struct Node* newNode = createNode(key);

    // If the tree is empty, the new node becomes the root
    if (root == NULL) {
        return newNode;
    }

    struct Node* parent = NULL;
    struct Node* current = root;

    // Traverse the tree to find the correct position
    while (current != NULL) {
        parent = current;

        if (key < current->data) {
            // Move left if key is smaller
            if (current->left == NULL) {
                break;  // Stop if we find an empty spot
            }
            current = current->left;
        } else {
            // Move right if key is greater
            if (current->rightThread == 1) {
                break;  // Stop if the right pointer is a thread
            }
            current = current->right;
        }
    }

    // Insert the new node in the appropriate position
    if (key < parent->data) {
        parent->left = newNode;
        newNode->right = parent;  // Right thread points to parent (inorder successor)
    } else {
        newNode->right = parent->right;  // New node's right will point to parent's right (inorder successor)
        parent->right = newNode;         // Parent's right now points to the new node
        parent->rightThread = 0;         // Parent now has a regular right child, not a thread
    }

    return root;
}

// Function for inorder traversal of a single-threaded binary tree
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* current = root;

    // Find the leftmost node
    while (current->left != NULL) {
        current = current->left;
    }

    // Traverse the tree using threads
    while (current != NULL) {
        printf("%d ", current->data);  // Visit the node

        // If right is a thread, follow the thread to the inorder successor
        if (current->rightThread == 1) {
            current = current->right;
        } else {
            // Otherwise, move to the leftmost node in the right subtree
            current = current->right;
            while (current != NULL && current->left != NULL) {
                current = current->left;
            }
        }
    }

    // Print a newline at the end for clean output
    printf("\n");
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    // Traverse left subtree
    if (root->left != NULL)
        preorder(root->left);

    // Traverse the right subtree or move to inorder successor
    if (!root->rightThread)
        preorder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Inserting elements into the tree
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    printf("Inorder traversal of single-threaded binary tree:\n");
    inorder(root);  // Expected output: 5 10 15 20 30

    printf("Preorder traversal of single-threaded binary tree:\n");
    preorder(root);  // Expected output: 20 10 5 15 30 

    // Print a newline at the end for clean output
    printf("\n");

    return 0;
}
