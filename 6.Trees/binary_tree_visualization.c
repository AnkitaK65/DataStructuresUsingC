#include <stdio.h>
#include <stdlib.h>

// Definition of a Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node into the BST (Binary Search Tree)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal of a binary tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to display a tree structure visually
void printTree(struct Node* root, int space) {
    int COUNT = 5;  // Number of spaces for indentation
    if (root == NULL)
        return;

    space += COUNT;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}

// Properties and characteristics of trees
void treeProperties() {
    printf("\n---- Tree Properties ----\n");
    printf("1. A tree is a hierarchical data structure.\n");
    printf("2. It consists of nodes, with a root node at the top.\n");
    printf("3. Each node can have zero or more child nodes.\n");
    printf("4. Binary Tree: A tree where each node has up to two children.\n");
    printf("5. Binary Search Tree (BST): A binary tree where left child has smaller value, right child has larger.\n");
    printf("6. Other types of trees include AVL Tree, Red-Black Tree, etc.\n");
    printf("--------------------------\n");
}

int main() {
    struct Node* root = NULL;

    // Constructing a binary search tree (BST)
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    printf("\nBinary Search Tree (BST) in inorder traversal: \n");
    inorder(root);
    printf("\n");

    // Print the tree visually
    printf("\nVisual representation of the Binary Search Tree (BST): \n");
    printTree(root, 0);

    // Print tree properties and characteristics
    treeProperties();

    return 0;
}
