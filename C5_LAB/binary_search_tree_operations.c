/*
Question 13: Write a program to create a Binary Search Tree and include the following operations:
a. Insertion (Recursive and Iterative Implementation)
b. Deletion by copying
c. Deletion by Merging
d. Search a number in BST
e. Display its preorder, postorder, and inorder traversals recursively
f. Display its preorder, postorder, and inorder traversals iteratively
g. Display its level-by-level traversal
h. Count the non-leaf nodes and leaf nodes
i. Display height of tree
j. Create a mirror image of tree
k. Check whether two BSTs are equal or not
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for BST Node
struct Node {
    int data; // Data stored in the node
    struct Node *left, *right;  // Pointer to the left and right child
};

// Function for creating a new node
struct Node* newNode(int data) {
     // Allocate memory for a new node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data; // Assign the provided data to the new node

    // Initialize the left and right child pointers to NULL -Since this is a newly created node, it has no children yet
    node->left = node->right = NULL; 
    return node; // Return the pointer to the newly created node
}

// 1. Recursive Insertion
struct Node* insertRecursive(struct Node* root, int data) {
     // Base case: If the root is NULL, create a new node and return it
    if (root == NULL)
        return newNode(data);

    // If the data to be inserted is smaller than the current node's data,
    // recursively insert into the left subtree    
    if (data < root->data)
        root->left = insertRecursive(root->left, data);

    // If the data to be inserted is greater than or equal to the current node's data,
    // recursively insert into the right subtree    
    else
        root->right = insertRecursive(root->right, data);

    // Return the root node after insertion
    return root;
}

// 2. Iterative Insertion
struct Node* insertIterative(struct Node* root, int data) {
    // Create a new node with the given data
    struct Node* new_node = newNode(data);

    // If the tree is empty, return the new node as the root
    if (root == NULL)
        return new_node;
    
    // Initialize a temporary pointer to traverse the tree starting from the root
    struct Node* temp = root;
    // Start a loop to find the correct position for insertion
    while (1) {
        // If the data is smaller than the current node's data, move to the left subtree
        if (data < temp->data) {
            // If the left child is NULL, insert the new node here and break
            if (temp->left == NULL) {
                temp->left = new_node;
                break;
            }
            // Otherwise, move to the left child
            temp = temp->left;
        }
        // If the data is greater than or equal to the current node's data, move to the right subtree
         else {
            // If the right child is NULL, insert the new node here and break
            if (temp->right == NULL) {
                temp->right = new_node;
                break;
            }
            // Otherwise, move to the right child
            temp = temp->right;
        }
    }
    // Return the root node, as it does not change during the insertion process
    return root;
}

// 3. Deletion by Copying
struct Node* deleteByCopying(struct Node* root, int data) {
    if (root == NULL) 
        return root; // Tree is empty or node not found.

    // Navigate to the node to be deleted.
    if (data < root->data) {
        root->left = deleteByCopying(root->left, data);
    } else if (data > root->data) {
        root->right = deleteByCopying(root->right, data);
    } else {
        // Node to be deleted is found.
        
        // Case 1: Node has no left child.
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        
        // Case 2: Node has no right child.
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 3: Node has two children.
        // Find the in-order successor (smallest in the right subtree).
        struct Node* inOrderSuccessor = root->right;
        while (inOrderSuccessor && inOrderSuccessor->left != NULL)
            inOrderSuccessor = inOrderSuccessor->left;
        
        // Replace the current node's data with the in-order successor's data.
        root->data = inOrderSuccessor->data;
        
        // Delete the in-order successor.
        root->right = deleteByCopying(root->right, inOrderSuccessor->data);
    }
    return root; // Return the modified tree root.
}

// 4. Deletion by Merging
// Merge two subtrees: Attach the right subtree to the rightmost node of the left subtree.
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL)
        return right;
    struct Node* temp = left;
    while (temp->right != NULL)
        temp = temp->right;
    temp->right = right;
    return left;
}

// Delete a node from the BST by merging subtrees.
struct Node* deleteByMerging(struct Node* root, int data) {
    if (root == NULL)
        return root; // Tree is empty or node not found.

    // Search for the node to delete.
    if (data < root->data) {
        root->left = deleteByMerging(root->left, data);
    } else if (data > root->data) {
        root->right = deleteByMerging(root->right, data);
    } else {
        // Node to delete is found.

        // Case 1: Node has no left child.
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root); // Free the memory of the current node.
            return temp;
        }

        // Case 2: Node has no right child.
        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root); // Free the memory of the current node.
            return temp;
        }

        // Case 3: Node has two children.
        struct Node* mergedSubtree = merge(root->left, root->right);
        free(root); // Free the memory of the current node.
        return mergedSubtree;
    }
    return root; // Return the modified root.
}

// 5. Search a number in BST
int search(struct Node* root, int data) {
    // If the tree is empty or we've reached a leaf node, return 0 (data not found)
    if (root == NULL)
        return 0;

    // If the data to be searched is smaller than the current node's data,
    // search in the left subtree recursively
    if (data < root->data)
        return search(root->left, data);

    // If the data to be searched is greater than the current node's data,
    // search in the right subtree recursively
    else if (data > root->data)
        return search(root->right, data);

    // If the data matches the current node's data, return 1 (data found)
    return 1;
}

// 6. Preorder Traversal (Recursive)
void preorderRecursive(struct Node* root) {
    // Base case: if the root is NULL, return (empty tree or end of a branch)
    if (root == NULL)
        return;
    
    // Step 1: Visit the root node (print the data)
    printf("%d ", root->data);

    // Step 2: Recursively traverse the left subtree
    preorderRecursive(root->left);

    // Step 3: Recursively traverse the right subtree
    preorderRecursive(root->right);
}

// 7. Postorder Traversal (Recursive)
void postorderRecursive(struct Node* root) {
    // Base case: if the root is NULL, return (empty tree or end of a branch)
    if (root == NULL)
        return;
    
    // Step 1: Recursively traverse the left subtree
    postorderRecursive(root->left);

    // Step 2: Recursively traverse the right subtree
    postorderRecursive(root->right);

    // Step 3: Visit the root node (print the data)
    printf("%d ", root->data);
}

// 8. Inorder Traversal (Recursive)
void inorderRecursive(struct Node* root) {
    // Base case: if the root is NULL, return (empty tree or end of a branch)
    if (root == NULL)
        return;

    // Step 1: Recursively traverse the left subtree
    inorderRecursive(root->left);

    // Step 2: Visit the root node (print the data)
    printf("%d ", root->data);

    // Step 3: Recursively traverse the right subtree
    inorderRecursive(root->right);
}

// 9. Preorder Traversal (Iterative)
void preorderIterative(struct Node* root) {
    // If the tree is empty, return (base case)
    if (root == NULL)
        return;

     // Initialize a stack to store nodes during traversal
    struct Node* stack[100];
    int top = -1; // Stack pointer

    // Push the root node onto the stack
    stack[++top] = root;

    // Continue processing nodes while the stack is not empty
    while (top >= 0) {
        // Pop a node from the stack (this is the current node to process)
        struct Node* temp = stack[top--];

        // Print the data of the current node (this is the "root" in preorder)
        printf("%d ", temp->data);

        // If the current node has a right child, push it onto the stack
        if (temp->right)
            stack[++top] = temp->right;

        // If the current node has a left child, push it onto the stack
        // Left child is pushed after the right child because the stack is LIFO (Last-In, First-Out)    
        if (temp->left)
            stack[++top] = temp->left;
    }
}

// 10. Postorder Traversal (Iterative)
void postorderIterative(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* stack[100];
    struct Node* lastVisited = NULL;
    int top = -1;
    while (root != NULL || top >= 0) {
        if (root != NULL) {
            stack[++top] = root;
            root = root->left;
        } else {
            struct Node* peekNode = stack[top];
            if (peekNode->right != NULL && peekNode->right != lastVisited) {
                root = peekNode->right;
            } else {
                printf("%d ", peekNode->data);
                lastVisited = stack[top--];
            }
        }
    }
}

// 11. Inorder Traversal (Iterative)
void inorderIterative(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// 12. Level-by-Level Traversal
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

// 13. Count Leaf and Non-Leaf Nodes
void countLeafNonLeaf(struct Node* root, int* leaf, int* nonLeaf) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        (*leaf)++;
    else
        (*nonLeaf)++;
    countLeafNonLeaf(root->left, leaf, nonLeaf);
    countLeafNonLeaf(root->right, leaf, nonLeaf);
}

// 14. Height of Tree
int height(struct Node* root) {
    if (root == NULL)
        return 0; // Base case for an empty tree
    int leftHeight = height(root->left); // Recursively calculate the height of the left subtree
    int rightHeight = height(root->right); // Recursively calculate the height of the right subtree
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // Add 1 for the current level
}

// 15. Create Mirror Image of Tree
/**
 * This function modifies the existing tree to create its mirror image.
 * It swaps the left and right subtrees recursively.
 * 
 * Note:
 * - After mirroring, the tree is no longer a Binary Search Tree (BST),
 *   as the property of BST (left < root < right) is violated.
 * - If the original BST properties are required for further operations,
 *   the tree should be converted back to BST using the mirror function again.
 */
struct Node* mirror(struct Node* root) {
    if (root == NULL)
        return root;
    // Swap left and right subtrees
    struct Node* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    return root;
}

// 16. Check if Two BSTs are Equal
int areEqual(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return (root1->data == root2->data) && areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}

// Main Function to Drive the Menu
int main() {
    struct Node* root = NULL;
    int choice, value;
    while (1) {
        printf("\n1. Recursive Insertion");
        printf("\n2. Iterative Insertion");
        printf("\n3. Deletion by copying");
        printf("\n4. Deletion by merging");
        printf("\n5. Search a number");
        printf("\n6. Preorder Traversal (Recursive)");
        printf("\n7. Postorder Traversal (Recursive)");
        printf("\n8. Inorder Traversal (Recursive)");
        printf("\n9. Preorder Traversal (Iterative)");
        printf("\n10. Postorder Traversal (Iterative)");
        printf("\n11. Inorder Traversal (Iterative)");
        printf("\n12. Level-by-Level Traversal");
        printf("\n13. Count Leaf and Non-Leaf Nodes");
        printf("\n14. Height of Tree");
        printf("\n15. Mirror Image of Tree");
        printf("\n16. Check if Two BSTs are Equal");
        printf("\n17. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertRecursive(root, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertIterative(root, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteByCopying(root, value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteByMerging(root, value);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf("Search result: %s\n", search(root, value) ? "Found" : "Not Found");
                break;
            case 6:
                printf("Preorder Traversal (Recursive): ");
                preorderRecursive(root);
                break;
            case 7:
                printf("Postorder Traversal (Recursive): ");
                postorderRecursive(root);
                break;
            case 8:
                printf("Inorder Traversal (Recursive): ");
                inorderRecursive(root);
                break;
            case 9:
                printf("Preorder Traversal (Iterative): ");
                preorderIterative(root);
                break;
            case 10:
                printf("Postorder Traversal (Iterative): ");
                postorderIterative(root);
                break;
            case 11:
                printf("Inorder Traversal (Iterative): ");
                inorderIterative(root);
                break;
            case 12:
                printf("Level-by-Level Traversal: ");
                levelOrderTraversal(root);
                break;
            case 13: {
                int leaf = 0, nonLeaf = 0;
                countLeafNonLeaf(root, &leaf, &nonLeaf);
                printf("Leaf Nodes: %d\n", leaf);
                printf("Non-Leaf Nodes: %d\n", nonLeaf);
                break;
            }
            case 14:
                printf("Height of Tree: %d\n", height(root));
                break;
            case 15:
                root = mirror(root);
                printf("Mirror Image Created\n");
                break;
            case 16: {
                struct Node* root2 = NULL;
                root2 = insertRecursive(root2, 10);
                root2 = insertRecursive(root2, 5);
                root2 = insertRecursive(root2, 20);
                printf("BSTs are equal: %s\n", areEqual(root, root2) ? "Yes" : "No");
                break;
            }
            case 17:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
