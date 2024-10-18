#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Threaded Binary Search Tree Node
struct Node {
    struct Node *left, *right;
    int info;
    bool lthread, rthread; // Threads indicate whether it's a real child or a thread
};

// Function declarations (forward declarations)
struct Node* delThreadedBST(struct Node* root, int dkey);
struct Node* caseA(struct Node* root, struct Node* par, struct Node* ptr);
struct Node* caseB(struct Node* root, struct Node* par, struct Node* ptr);
struct Node* caseC(struct Node* root, struct Node* par, struct Node* ptr);

// Function to create a new node
struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->lthread = true;
    newNode->rthread = true;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the threaded binary search tree
struct Node* insert(struct Node* root, int key) {
    struct Node *ptr = root;
    struct Node *par = NULL; // This will be parent of the new node
    
    // Search for the parent under which the new node will be inserted
    while (ptr != NULL) {
        if (key == ptr->info) {
            printf("Duplicate key not allowed!\n");
            return root;
        }
        
        par = ptr;
        
        if (key < ptr->info) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        } else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    
    // Create a new node
    struct Node* newNode = createNode(key);
    
    if (par == NULL) { // If the tree was empty, the new node is the root
        root = newNode;
        newNode->left = NULL;
        newNode->right = NULL;
    } else if (key < par->info) { // Insert newNode to the left of par
        newNode->left = par->left;
        newNode->right = par;
        par->lthread = false;
        par->left = newNode;
    } else { // Insert newNode to the right of par
        newNode->right = par->right;
        newNode->left = par;
        par->rthread = false;
        par->right = newNode;
    }

    return root;
}

// Function to find the inorder successor
struct Node* inorderSuccessor(struct Node *ptr) {
    if (ptr->rthread)
        return ptr->right;

    ptr = ptr->right;
    while (ptr->lthread == false)
        ptr = ptr->left;

    return ptr;
}

// Function to find inorder predecessor
struct Node* inorderPredecessor(struct Node *ptr) {
    if (ptr->lthread)
        return ptr->left;

    ptr = ptr->left;
    while (ptr->rthread == false)
        ptr = ptr->right;

    return ptr;
}

// Case A: Node to be deleted has no children (is a leaf node)
struct Node* caseA(struct Node* root, struct Node* par, struct Node* ptr) {
    if (par == NULL)
        root = NULL;
    else if (ptr == par->left) {
        par->lthread = true;
        par->left = ptr->left;
    } else {
        par->rthread = true;
        par->right = ptr->right;
    }
    free(ptr);
    return root;
}

// Case B: Node to be deleted has one child
struct Node* caseB(struct Node* root, struct Node* par, struct Node* ptr) {
    struct Node* child;

    if (ptr->lthread == false)
        child = ptr->left;
    else
        child = ptr->right;

    if (par == NULL)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    struct Node* pred = inorderPredecessor(ptr);
    struct Node* succ = inorderSuccessor(ptr);

    if (ptr->lthread == false)
        pred->right = succ;
    else if (ptr->rthread == false)
        succ->left = pred;

    free(ptr);
    return root;
}

// Case C: Node to be deleted has two children
struct Node* caseC(struct Node* root, struct Node* par, struct Node* ptr) {
    struct Node* succ = inorderSuccessor(ptr);
    int val = succ->info;
    root = delThreadedBST(root, succ->info);  // Now correctly declared
    ptr->info = val;
    return root;
}

// Deletes a node from the threaded BST
struct Node* delThreadedBST(struct Node* root, int dkey) {
    struct Node *par = NULL, *ptr = root;
    int found = 0;

    // Search for the node to delete
    while (ptr != NULL) {
        if (dkey == ptr->info) {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info) {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        } else {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }

    if (!found) {
        printf("dkey not present in tree\n");
        return root;
    }

    // Apply appropriate case
    if (!ptr->lthread && !ptr->rthread)       // Case C: Two children
        root = caseC(root, par, ptr);
    else if (!ptr->lthread || !ptr->rthread)  // Case B: One child
        root = caseB(root, par, ptr);
    else                                      // Case A: No child
        root = caseA(root, par, ptr);

    return root;
}

// Function for inorder traversal of the threaded BST
void inorder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    struct Node* ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = inorderSuccessor(ptr);
    }
    printf("\n");
}

// Sample main function to test insertion and deletion in the threaded BST
int main() {
    struct Node* root = NULL;

    // Insert values into the tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    // Perform In-order Traversal
    printf("In-order traversal before deletion: ");
    inorder(root);

    // Delete a node
    root = delThreadedBST(root, 5);
    printf("In-order traversal after deletion: ");
    inorder(root);

    return 0;
}
