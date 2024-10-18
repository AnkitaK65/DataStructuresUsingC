#include <stdio.h>
#include <stdlib.h>

//         50
//        /  \
//      30    70
//     /  \   /  \
//    20  40 60  80


// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    // Dynamically allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL; // Initialize children to NULL
    return newNode;
}

// Function to insert values into the binary tree
struct Node* insertNode(struct Node* root, int value) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Recur down the tree and insert the value in the correct position
    if (value < root->data) {
        root->left = insertNode(root->left, value); // Insert in the left subtree
    } else if (value > root->data) {
        root->right = insertNode(root->right, value); // Insert in the right subtree
    }

    return root;
}

// In-order traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse the left subtree
        printf("%d ", root->data);     // Visit the root node
        inorderTraversal(root->right); // Traverse the right subtree
    }
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);     // Visit the root node
        preorderTraversal(root->left); // Traverse the left subtree
        preorderTraversal(root->right);// Traverse the right subtree
    }
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // Traverse the left subtree
        postorderTraversal(root->right); // Traverse the right subtree
        printf("%d ", root->data);       // Visit the root node
    }
}

// Function to calculate the height of the binary tree
int height(struct Node* node) {
    if (node == NULL)
        return 0; // If the node is NULL, the height is 0

    // Recursively calculate the height of the left and right subtrees, then return the greater one + 1
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Helper function to print the nodes at a given level
void printCurrentLevel(struct Node* root, int level) {
    if (root == NULL)
        return;

    if (level == 1) {
        // Print the data when we're at the desired level
        printf("%d ", root->data);
    } else if (level > 1) {
        // Recur for the next level
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Function for level-order traversal (Breadth-First Traversal)
void levelOrderTraversal(struct Node* root) {
    int h = height(root); // Get the height of the tree
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i); // Print nodes at each level
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting values into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    /*
    // Inserting values into the binary tree (Non-BST)
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    */


    // Traversing the tree using different traversal techniques
    printf("In-order Traversal: ");
    inorderTraversal(root);  // In-order: Left, Root, Right
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderTraversal(root); // Pre-order: Root, Left, Right
    printf("\n");

    printf("Post-order Traversal: ");
    postorderTraversal(root); // Post-order: Left, Right, Root
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrderTraversal(root); // Level-order: Print each level of the tree
    printf("\n");

    return 0;
}