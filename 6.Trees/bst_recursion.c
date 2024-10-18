#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive insertion into binary tree
struct Node* insertRecursive(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data)
        node->left = insertRecursive(node->left, data);
    else if (data > node->data)
        node->right = insertRecursive(node->right, data);
    return node;
}

// Recursive Inorder Traversal
void inorderRecursive(struct Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

// Recursive Preorder Traversal
void preorderRecursive(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

// Recursive Postorder Traversal
void postorderRecursive(struct Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Recursive deletion in binary tree
struct Node* deleteRecursive(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteRecursive(root->left, data);
    else if (data > root->data)
        root->right = deleteRecursive(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* succParent = root;
        struct Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        root->data = succ->data;
        succParent->left = deleteRecursive(succ, succ->data);
    }

    return root;
}

// Driver function
int main() {
    struct Node* root = NULL;
    root = insertRecursive(root, 50);
    insertRecursive(root, 30);
    insertRecursive(root, 20);
    insertRecursive(root, 40);
    insertRecursive(root, 70);
    insertRecursive(root, 60);
    insertRecursive(root, 80);

    printf("Inorder traversal: ");
    inorderRecursive(root);
    printf("\nPreorder traversal: ");
    preorderRecursive(root);
    printf("\nPostorder traversal: ");
    postorderRecursive(root);

    root = deleteRecursive(root, 50);
    printf("\nInorder traversal after deletion: ");
    inorderRecursive(root);

    return 0;
}
