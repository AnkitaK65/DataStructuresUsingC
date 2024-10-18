#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inorder traversal to store elements of the tree in sorted order
void storeInorder(struct Node* root, int nodes[], int* index) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    storeInorder(root->left, nodes, index);

    // Store the node data in the array
    nodes[(*index)++] = root->data;

    // Traverse the right subtree
    storeInorder(root->right, nodes, index);
}

// Function to build a balanced BST from a sorted array
struct Node* buildBalancedTree(int nodes[], int start, int end) {
    // Base case: if start is greater than end, return NULL
    if (start > end) {
        return NULL;
    }

    // Get the middle element and make it the root
    int mid = (start + end) / 2;
    struct Node* root = newNode(nodes[mid]);

    // Recursively build the left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to convert an unbalanced BST to a balanced BST
struct Node* balanceBST(struct Node* root) {
    int nodes[1000];  // Array to store nodes in sorted order
    int index = 0;

    // Store nodes in inorder traversal (sorted order)
    storeInorder(root, nodes, &index);

    // Build and return a balanced BST from the sorted nodes
    return buildBalancedTree(nodes, 0, index - 1);
}

// Function to perform inorder traversal and print the tree
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Constructing an unbalanced BST
    //        10
    //       /  \
    //      5    15
    //     /       \
    //    2         20
    //   /
    //  1

    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(2);
    root->left->left->left = newNode(1);
    root->right = newNode(15);
    root->right->right = newNode(20);

    // Convert unbalanced BST to a balanced BST
    struct Node* balancedRoot = balanceBST(root);

    // Print the balanced BST using inorder traversal
    inorder(balancedRoot);
    printf("\n");

    return 0;
}
