#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the Node structure for the Threaded Binary Tree
struct Node 
{ 
    struct Node *left, *right; // Pointers to left and right child
    int info;                  // Value stored in the node

    // False if left pointer points to predecessor in Inorder Traversal
    bool lthread; 

    // False if right pointer points to successor in Inorder Traversal
    bool rthread; 
}; 

// Function to insert a Node in Binary Threaded Tree 
struct Node *insert(struct Node *root, int ikey) 
{ 
    // Searching for a Node with the given value
    struct Node *ptr = root; 
    struct Node *par = NULL; // Parent of the key to be inserted 

    while (ptr != NULL) 
    { 
        // If the key already exists, return the current tree
        if (ikey == (ptr->info)) 
        { 
            printf("Duplicate Key!\n"); 
            return root; 
        } 

        par = ptr; // Update parent pointer 

        // Moving on left subtree 
        if (ikey < ptr->info) 
        { 
            if (ptr->lthread == false) // If left thread is false, move to left child
                ptr = ptr->left; 
            else
                break; // Can't go left, break the loop
        } 
        // Moving on right subtree 
        else
        { 
            if (ptr->rthread == false) // If right thread is false, move to right child
                ptr = ptr->right; 
            else
                break; // Can't go right, break the loop
        } 
    } 

    // Create a new node
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node)); 
    tmp->info = ikey; 
    tmp->lthread = true; 
    tmp->rthread = true; 

    // Three cases for insertion
    if (par == NULL) // Case 1: Tree is empty
    { 
        root = tmp; // New node becomes the root
        tmp->left = NULL; 
        tmp->right = NULL; 
    } 
    else if (ikey < (par->info)) // Case 2: New node is the left child of parent
    { 
        tmp->left = par->left; // Set the left child of the new node
        tmp->right = par; // Set the right child of the new node to the parent
        par->lthread = false; // Set left thread of parent to false
        par->left = tmp; // Update parent’s left pointer to the new node
    } 
    else // Case 3: New node is the right child of parent
    { 
        tmp->left = par; // Set the left child of the new node to parent
        tmp->right = par->right; // Set the right child of the new node
        par->rthread = false; // Set right thread of parent to false
        par->right = tmp; // Update parent’s right pointer to the new node
    } 

    return root; // Return the updated root of the tree
} 

// Returns inorder successor using rthread 
struct Node *inorderSuccessor(struct Node *ptr) 
{ 
    // If rthread is set, we can quickly find the successor
    if (ptr->rthread == true) 
        return ptr->right; 

    // Else return the leftmost child of the right subtree
    ptr = ptr->right; 
    while (ptr->lthread == false) 
        ptr = ptr->left; 
    return ptr; 
} 

// Function to print the threaded tree in inorder
void inorder(struct Node *root) 
{ 
    if (root == NULL) 
    {
        printf("Tree is empty\n");
        return; 
    }

    // Reach leftmost node
    struct Node *ptr = root; 
    while (ptr->lthread == false) 
        ptr = ptr->left; 

    // One by one print successors
    while (ptr != NULL) 
    { 
        printf("%d ", ptr->info); 
        ptr = inorderSuccessor(ptr); 
    } 
} 

// Driver Program 
int main() 
{ 
    struct Node *root = NULL; 

    // Inserting values into the threaded binary tree
    root = insert(root, 20); 
    root = insert(root, 10); 
    root = insert(root, 30); 
    root = insert(root, 5); 
    root = insert(root, 16); 
    root = insert(root, 14); 
    root = insert(root, 17); 
    root = insert(root, 13); 

    // Printing the threaded binary tree in inorder
    inorder(root); 

    printf("\n");
    return 0; 
} 
