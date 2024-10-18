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

// Iterative insertion into binary tree
struct Node* insertIterative(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) return newNode;

    struct Node* current = root;
    struct Node* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Iterative Inorder Traversal
void inorderIterative(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Iterative Preorder Traversal
void preorderIterative(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    
    if (root != NULL) stack[++top] = root;
    
    while (top != -1) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);
        
        if (current->right != NULL) stack[++top] = current->right;
        if (current->left != NULL) stack[++top] = current->left;
    }
}

// Iterative Postorder Traversal
void postorderIterative(struct Node* root) {
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    
    if (root != NULL) stack1[++top1] = root;
    
    while (top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;
        
        if (current->left != NULL) stack1[++top1] = current->left;
        if (current->right != NULL) stack1[++top1] = current->right;
    }
    
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Iterative deletion in binary tree
struct Node* deleteIterative(struct Node* root, int data) {
    struct Node* parent = NULL;
    struct Node* current = root;
    
    // Find the node to delete
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    if (current == NULL) return root;  // Node not found

    // Node with one or no children
    if (current->left == NULL || current->right == NULL) {
        struct Node* newCurr = (current->left != NULL) ? current->left : current->right;
        
        if (parent == NULL)  // Root node to be deleted
            root = newCurr;
        else if (parent->left == current)
            parent->left = newCurr;
        else
            parent->right = newCurr;
        
        free(current);
    } else {
        // Node with two children: Find inorder successor
        struct Node* succParent = current;
        struct Node* succ = current->right;
        
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        
        current->data = succ->data;
        
        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        
        free(succ);
    }
    
    return root;
}

// Driver function
int main() {
    struct Node* root = NULL;
    root = insertIterative(root, 50);
    insertIterative(root, 30);
    insertIterative(root, 20);
    insertIterative(root, 40);
    insertIterative(root, 70);
    insertIterative(root, 60);
    insertIterative(root, 80);

    printf("Inorder traversal: ");
    inorderIterative(root);
    printf("\nPreorder traversal: ");
    preorderIterative(root);
    printf("\nPostorder traversal: ");
    postorderIterative(root);

    root = deleteIterative(root, 50);
    printf("\nInorder traversal after deletion: ");
    inorderIterative(root);

    return 0;
}
