#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for traversal
struct Stack {
    struct Node** arr;
    int top;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node* node) {
    stack->arr[++stack->top] = node;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

// Function to peek the top node of the stack
struct Node* peek(struct Stack* stack) {
    return stack->arr[stack->top];
}

// Function for iterative in-order traversal of the BST
void inOrderTraversal(struct Node* root) {
    struct Stack* stack = createStack(100); // You can adjust the size
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = pop(stack);
        printf("%d ", current->data); // Visit the node

        // Move to the right subtree
        current = current->right;
    }

    // Free the stack memory
    free(stack->arr);
    free(stack);
}

// Function for iterative pre-order traversal of the BST
void preOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack(100); // You can adjust the size
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(stack);
        printf("%d ", current->data); // Visit the node

        // Push right child first so that left child is processed first
        if (current->right != NULL) {
            push(stack, current->right);
        }
        if (current->left != NULL) {
            push(stack, current->left);
        }
    }

    // Free the stack memory
    free(stack->arr);
    free(stack);
}

// Function for iterative post-order traversal of the BST
void postOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack(100); // You can adjust the size
    struct Node* current = root;
    struct Node* lastVisited = NULL;

    while (!isEmpty(stack) || current != NULL) {
        // Reach the leftmost node
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // Peek the node at the top of the stack
        current = peek(stack);

        // If the right child is NULL or already visited
        if (current->right == NULL || current->right == lastVisited) {
            // Visit the node
            printf("%d ", current->data);
            lastVisited = pop(stack); // Update last visited node
            current = NULL; // Set current to NULL for the next iteration
        } else {
            // Move to the right child
            current = current->right;
        }
    }

    // Free the stack memory
    free(stack->arr);
    free(stack);
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
